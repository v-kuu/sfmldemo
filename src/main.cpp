#include <SFML/Graphics.hpp>
#include "ResourceBank.hpp"
#include "Scene.hpp"
#include "Asteroid.hpp"
#include "Player.hpp"
#include "Projectile.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Asteroid Game");
    window.setFramerateLimit(60);
	ResourceBank::initialize(window);
	Scene map(window);
	sf::View main(map.bounds.getCenter(), {1920, 1080});
	main.zoom(1.3f);
	map.frameBuffer.setView(main);
	Player player(map.bounds);
	sf::Clock clock;
	for (int i = 0; i < 32; ++i)
		map.asteroids.emplace_back((map.bounds));
	for (int i = 0; i < 5; ++i)
		Projectile::addProjectile(map.bounds);

    while (window.isOpen())
    {
        window.clear();
		map.frameBuffer.clear();
		map.drawBg();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
					window.close();
			}
        }
		float delta = clock.restart().asSeconds();
		for (auto &ast : map.asteroids)
		{
			ast.update(delta);
			ast.draw(map.frameBuffer);
			player.getHit(ast.hitbox());
		}
		player.update(delta);
		Projectile::drawAll(map.frameBuffer, delta, map);
		player.draw(map.frameBuffer);
		main.setCenter(player.center());
		map.frameBuffer.display();
		map.frameBuffer.setView(main);
		sf::Sprite final(map.frameBuffer.getTexture());
		window.draw(final, &(ResourceBank::shaders["CRT"]));
        window.display();
    }
}

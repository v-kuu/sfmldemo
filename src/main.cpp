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

	sf::Vector2<float> accel;
	sf::Angle rot;
    while (window.isOpen())
    {
        window.clear();
		map.frameBuffer.clear();
		accel = {0, 0};
		rot = sf::degrees(0);
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			accel += {0, -10};
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			accel += {0, 10};
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			accel += {-10, 0};
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			accel += {10, 0};
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			rot += sf::degrees(-5);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			rot += sf::degrees(5);
		float delta = clock.restart().asSeconds();
		for (auto &ast : map.asteroids)
		{
			ast.draw(map.frameBuffer, delta);
			player.getHit(ast.hitbox());
		}
		Projectile::drawAll(map.frameBuffer, delta, map);
		player.update(accel, rot, delta);
		player.draw(map.frameBuffer, delta);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			player.fire();
		main.setCenter(player.center());
		map.frameBuffer.display();
		map.frameBuffer.setView(main);
		sf::Sprite final(map.frameBuffer.getTexture());
		window.draw(final, &(ResourceBank::shaders["CRT"]));
        window.display();
    }
}

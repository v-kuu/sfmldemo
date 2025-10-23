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
	ResourceBank::initialize();
	Scene map;
	sf::View main(map.bounds.getCenter(), map.bounds.size);
	window.setView(main);
	Player player(map.bounds);
	sf::Clock clock;
	for (int i = 0; i < 32; ++i)
		map.objects.push_back(Asteroid::generateRandom(map.bounds));
	for (int i = 0; i < 5; ++i)
		Projectile::addProjectile(map.bounds);

	sf::Vector2<float> accel;
	sf::Angle rot;
    while (window.isOpen())
    {
		accel = {0, 0};
		rot = sf::degrees(0);
        window.clear();
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
		for (auto it = map.objects.begin(); it != map.objects.end(); ++it)
			(*it)->draw(window, delta);
		Projectile::drawAll(window, delta, map);
		player.update(accel, rot, delta);
		player.draw(window, delta);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			player.fire();
        window.display();
    }
}

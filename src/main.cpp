#include <SFML/Graphics.hpp>
#include "ResourceBank.hpp"
#include "Scene.hpp"
#include "Asteroid.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Asteroid Game");
    window.setFramerateLimit(60);
	ResourceBank::initialize();
	Scene map;
	sf::View main(map.bounds.getCenter(), map.bounds.size);
	window.setView(main);
	sf::Clock clock;
	for (int i = 0; i < 32; ++i)
		map.objects.push_back(Asteroid::generateRandom(map.bounds));
    while (window.isOpen())
    {
        window.clear();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
		float delta = clock.restart().asSeconds();
		for (auto it = map.objects.begin(); it != map.objects.end(); ++it)
			(*it)->draw(window, delta);

        window.display();
    }
}

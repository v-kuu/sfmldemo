#include <SFML/Graphics.hpp>
#include "ResourceBank.hpp"
#include "Scene.hpp"
#include "Asteroid.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(60);
	ResourceBank::initialize();
	Scene map;
	map.objects.push_back(std::make_unique<Asteroid>());
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
		for (auto it = map.objects.begin(); it != map.objects.end(); ++it)
			(*it)->draw(window);

        window.display();
    }
}

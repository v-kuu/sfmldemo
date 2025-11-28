#include <SFML/Graphics.hpp>
#include "Scene.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Asteroid Game", sf::State::Fullscreen);
    window.setFramerateLimit(60);

	ResourceBank::initialize(window);
	Scene map(window, 32);
	sf::Clock clock;

    while (window.isOpen())
    {
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
		float delta = clock.restart().asSeconds();
		map.update(delta);
		sf::Sprite final(map.frameBuffer.getTexture());
		window.draw(final, &(ResourceBank::shaders["CRT"]));
        window.display();
    }
}

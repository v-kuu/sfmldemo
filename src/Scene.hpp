#pragma once
#include "Asteroid.hpp"
#include <vector>
#include <memory>

struct	Scene
{
		Scene(void) = delete;
		Scene(sf::RenderWindow &window);
		void drawBg(void);

		sf::Sprite background;
		sf::FloatRect bounds;
		std::vector<Asteroid> asteroids;
		sf::RenderTexture frameBuffer;
};

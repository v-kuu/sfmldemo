#pragma once
#include "Asteroid.hpp"
#include <vector>
#include <memory>

struct	Scene
{
		Scene(void);
		void drawBg(sf::RenderWindow &target) const;

		sf::Sprite background;
		sf::FloatRect bounds;
		std::vector<Asteroid> asteroids;
};

#pragma once
#include "Asteroid.hpp"
#include <vector>
#include <memory>

struct	Scene
{
		Scene(void);

		std::vector<Asteroid> asteroids;
		sf::FloatRect bounds;
};

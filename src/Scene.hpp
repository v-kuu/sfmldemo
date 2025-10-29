#pragma once
#include "Asteroid.hpp"
#include "Player.hpp"
#include <vector>
#include <memory>

class	Asteroid;
class	Player;

struct	Scene
{
		Scene(void) = delete;
		Scene(sf::RenderWindow &window, int asteroid_amount);
		void drawBg(void);
		void update(float delta);
		bool detectCollission(sf::FloatRect first, sf::FloatRect second);

		sf::Sprite background;
		sf::FloatRect bounds;
		std::vector<Asteroid> asteroids;
		sf::RenderTexture frameBuffer;
		sf::View cam;
		Player player;
};

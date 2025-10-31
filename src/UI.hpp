#pragma once
#include "ResourceBank.hpp"
#include "Player.hpp"
#include <vector>

class UI
{
	public:
		UI(void) = delete;
		UI(const Player &player);
		void draw(sf::RenderTexture &target);

	private:
		std::vector<sf::Sprite> _hpSprites;
		std::vector<sf::Sprite> _hitSprites;
		const Player &_player;
};

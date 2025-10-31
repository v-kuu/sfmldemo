#include "UI.hpp"

UI::UI(const Player &player) : _player(player)
{
	for (int i = 0; i < _player.hp(); ++i)
	{
		_hpSprites.emplace_back(
				ResourceBank::textures["Atlas"],
				ResourceBank::subTextures["HP"]);
		_hpSprites[i].setPosition({30.f + 40.f * i, 30.f});
	}
}

void UI::draw(sf::RenderTexture &target)
{
	for (int i = 0; i < _player.hp(); ++i)
		target.draw(_hpSprites[i]);
}

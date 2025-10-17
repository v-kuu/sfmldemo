#pragma once

#include <map>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

struct	ResourceBank
{
	ResourceBank(void) = delete;

	static void initialize(void);

	static std::map<std::string, sf::Texture> textures;
};

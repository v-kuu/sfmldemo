#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Projectile.hpp"

struct	ResourceBank
{
	ResourceBank(void) = delete;

	static void initialize(sf::RenderWindow &window);

	static std::map<std::string, sf::Texture> textures;
	static std::map<std::string, sf::IntRect> subTextures;
	static std::map<std::string, sf::Shader> shaders;
};

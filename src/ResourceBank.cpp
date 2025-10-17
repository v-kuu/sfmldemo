#include "ResourceBank.hpp"

std::map<std::string, sf::Texture> ResourceBank::textures = {};

void ResourceBank::initialize(void)
{
	sf::Texture temp;
	if (!temp.loadFromFile("textures/meteorGrey_big1.png"))
		std::cerr << "Failed to load asteroid texture" << std::endl;
	textures["Asteroid"] = sf::Texture(temp);
}

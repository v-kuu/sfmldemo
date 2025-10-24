#include "ResourceBank.hpp"

std::map<std::string, sf::Texture> ResourceBank::textures = {};

void ResourceBank::initialize(void)
{
	sf::Texture temp;
	if (!temp.loadFromFile("textures/meteorGrey_big1.png"))
		std::cerr << "Failed to load asteroid texture" << std::endl;
	textures["Asteroid"] = sf::Texture(temp);
	if (!temp.loadFromFile("textures/playerShip1_blue.png"))
		std::cerr << "Failed to load player texture" << std::endl;
	textures["Player"] = sf::Texture(temp);
	if (!temp.loadFromFile("textures/laserGreen08.png"))
		std::cerr << "Failed to load player texture" << std::endl;
	textures["Laser"] = sf::Texture(temp);
	if (!temp.loadFromFile("textures/purple.png"))
		std::cerr << "Failed to load background texture" << std::endl;
	textures["Background"] = sf::Texture(temp);
	textures["Background"].setRepeated(true);
}

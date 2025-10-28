#include "ResourceBank.hpp"

std::map<std::string, sf::Texture> ResourceBank::textures = {};
std::map<std::string, sf::Shader> ResourceBank::shaders = {};

void ResourceBank::initialize(void)
{
	sf::Texture tex;
	if (!tex.loadFromFile("textures/meteorGrey_big1.png"))
		std::cerr << "Failed to load asteroid texture" << std::endl;
	textures["Asteroid"] = sf::Texture(tex);
	if (!tex.loadFromFile("textures/playerShip1_blue.png"))
		std::cerr << "Failed to load player texture" << std::endl;
	textures["Player"] = sf::Texture(tex);
	if (!tex.loadFromFile("textures/laserGreen08.png"))
		std::cerr << "Failed to load player texture" << std::endl;
	textures["Laser"] = sf::Texture(tex);
	if (!tex.loadFromFile("textures/purple.png"))
		std::cerr << "Failed to load background texture" << std::endl;
	textures["Background"] = sf::Texture(tex);
	textures["Background"].setRepeated(true);

	sf::Shader shader;
	if (!shader.loadFromFile("shaders/crt.frag", sf::Shader::Type::Fragment))
		std::cerr << "Failed to load crt shader" << std::endl;
	shaders["CRT"] = std::move(shader);
}

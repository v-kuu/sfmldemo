#include "ResourceBank.hpp"

std::map<std::string, sf::Texture> ResourceBank::textures = {};
std::map<std::string, sf::IntRect> ResourceBank::subTextures = {};
std::map<std::string, sf::Shader> ResourceBank::shaders = {};

void ResourceBank::initialize(sf::RenderWindow &window)
{
	sf::Texture tex;
	if (!tex.loadFromFile("textures/sheet.png"))
		std::cerr << "Failed to load texture atlas" << std::endl;
	textures["Atlas"] = sf::Texture(tex);
	subTextures["Asteroid"] = sf::IntRect({224, 748}, {101, 84});
	subTextures["Player"] = sf::IntRect({211, 941}, {99, 75});
	subTextures["Laser"] = sf::IntRect({848, 738}, {13, 37});
	if (!tex.loadFromFile("textures/purple.png"))
		std::cerr << "Failed to load background texture" << std::endl;
	textures["Background"] = sf::Texture(tex);
	textures["Background"].setRepeated(true);

	sf::Shader shader;
	if (!shader.loadFromFile("shaders/crt.frag", sf::Shader::Type::Fragment))
		std::cerr << "Failed to load crt shader" << std::endl;
	shader.setUniform("texture", sf::Shader::CurrentTexture);
	shader.setUniform("resolution", sf::Vector2f(window.getSize()));
	shaders["CRT"] = std::move(shader);
}

#include "Scene.hpp"

Scene::Scene(void) : bounds({0, 0}, {5000, 5000}),
	background(ResourceBank::textures.find("Background")->second, {{0, 0},{5000, 5000}})
{
}

void Scene::drawBg(sf::RenderWindow &target) const
{
	sf::Shader &shader = ResourceBank::shaders["CRT"];
	target.draw(background, &shader);
}

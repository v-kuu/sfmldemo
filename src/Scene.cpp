#include "Scene.hpp"

Scene::Scene(sf::RenderWindow &window) : bounds({0, 0}, {5000, 5000}),
	background(ResourceBank::textures.find("Background")->second, {{0, 0},{5000, 5000}}),
	frameBuffer(window.getSize())
{
}

void Scene::drawBg(void)
{
	frameBuffer.draw(background);
}

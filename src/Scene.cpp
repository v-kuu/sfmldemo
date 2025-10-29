#include "Scene.hpp"

Scene::Scene(sf::RenderWindow &window, int asteroid_amount)
	: bounds({0, 0}, {5000, 5000}),
	asteroids({}),
	background(ResourceBank::textures["Background"], {{0, 0},{5000, 5000}}),
	frameBuffer(window.getSize()),
	cam(bounds.getCenter(), {1920, 1080}),
	player(bounds)
{
	cam.zoom(1.3f);
	frameBuffer.setView(cam);
	for (int i = 0; i < asteroid_amount; ++i)
		asteroids.emplace_back((bounds));
	for (int i = 0; i < 5; ++i)
		Projectile::addProjectile(bounds);
}

void Scene::drawBg(void)
{
	frameBuffer.draw(background);
}

void Scene::update(float delta)
{
	frameBuffer.clear();
	drawBg();
	for (auto &ast : asteroids)
	{
		ast.update(delta);
		ast.draw(frameBuffer);
		if (detectCollission(player.hitbox(), ast.hitbox()))
		{
			player.getHit();
			ast.getHit();
		}
	}
	player.update(delta);
	for (auto &pr : Projectile::projectiles())
	{
		pr.update(delta);
		pr.draw(frameBuffer);
		if (pr.isSpawned())
		{
			for (auto &obj : asteroids)
				if (detectCollission(obj.hitbox(), pr.hitbox()))
				{
					obj.getHit();
					pr.getHit();
				}
		}
	}
	player.draw(frameBuffer);
	cam.setCenter(player.center());
	frameBuffer.setView(cam);
	frameBuffer.display();
}

bool Scene::detectCollission(sf::FloatRect first, sf::FloatRect second)
{
	if (first.findIntersection(second) != std::nullopt)
		return (true);
	return (false);
}

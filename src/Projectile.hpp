#pragma once
#include "IObject.hpp"
#include "Scene.hpp"
#include "ResourceBank.hpp"
#include "Player.hpp"

class	Player;

class	Projectile : public IObject
{
	public:
		static int max;
		static int amount;
		static int next;
		Projectile(void);

		void draw(sf::RenderWindow &target, float delta) override;
		bool getHit(sf::FloatRect obj) override;
		static void drawAll(sf::RenderWindow &target, float delta, Scene &map);
		static void addProjectile(sf::FloatRect sceneBounds);
		static void fire(const Player &source);

	private:
		sf::Sprite _sprite;
		sf::Vector2<float> _velocity;
		static sf::FloatRect _sceneBounds;
		static std::vector<Projectile> _projectiles;

		void _spawn(const Player &source);
		void _despawn(void);
};

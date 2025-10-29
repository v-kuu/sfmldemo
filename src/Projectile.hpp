#pragma once
#include "IObject.hpp"
#include "ResourceBank.hpp"

class	Projectile : public IObject
{
	public:
		static int max;
		static int amount;
		static int next;
		Projectile(void);

		void update(float delta) override;
		void draw(sf::RenderTexture &target) override;
		void getHit() override;
		sf::FloatRect hitbox(void) const override;
		bool isSpawned(void) const;
		static void addProjectile(sf::FloatRect sceneBounds);
		static void fire(sf::Vector2f pos, sf::Angle rot, sf::Vector2f vel);
		static std::vector<Projectile> &projectiles(void);

	private:
		sf::Sprite _sprite;
		sf::Vector2<float> _velocity;
		static sf::FloatRect _sceneBounds;
		static std::vector<Projectile> _projectiles;

		void _spawn(sf::Vector2f pos, sf::Angle rot, sf::Vector2f vel);
		void _despawn(void);
};

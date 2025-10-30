#pragma once
#include "IObject.hpp"
#include "ResourceBank.hpp"
#include "Projectile.hpp"
#include <cmath>

class	Projectile;

class	Player : public IObject
{
	public:
		Player(void) = delete;
		Player(sf::FloatRect sceneBounds, sf::RenderWindow &window);

		void update(float delta) override;
		void draw(sf::RenderTexture &target) override;
		void getHit() override;
		sf::FloatRect hitbox(void) const override;

		sf::Vector2<float> center(void) const;
		sf::Vector2<float> velocity(void) const;
		sf::Angle orientation(void) const;

	private:
		sf::RenderWindow &_window;
		sf::Sprite _sprite;
		sf::Vector2<float> _velocity;
		sf::Angle _orientation;
		sf::FloatRect _sceneBounds;
		float _topSpeed;
		float _fireCooldown;
	
		void _fire(void);
		sf::Angle _trackMouse(void);
};

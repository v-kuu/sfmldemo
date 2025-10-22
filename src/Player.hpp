#pragma once
#include "IObject.hpp"
#include "ResourceBank.hpp"
#include "Projectile.hpp"

class	Projectile;

class	Player : public IObject
{
	public:
		Player(void) = delete;
		Player(sf::FloatRect sceneBounds);

		void draw(sf::RenderWindow &target, float delta) override;
		void update(sf::Vector2<float> accel, sf::Angle rot);
		std::unique_ptr<Projectile> fire(void) const;

		sf::Vector2<float> center(void) const;
		sf::Angle orientation(void) const;

	private:
		sf::Sprite _sprite;
		sf::Vector2<float> _velocity;
		sf::Angle _orientation;
		sf::FloatRect _sceneBounds;
		float _topSpeed;
};

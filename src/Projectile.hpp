#pragma once
#include "IObject.hpp"
#include "ResourceBank.hpp"
#include "Player.hpp"

class	Player;

class	Projectile : public IObject
{
	public:
		Projectile(void) = delete;
		Projectile(const Player &source);

		void draw(sf::RenderWindow &target, float delta) override;

	private:
		sf::Sprite _sprite;
		sf::Vector2<float> _velocity;
};

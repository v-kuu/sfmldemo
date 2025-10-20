#pragma once

#include "IObject.hpp"
#include "ResourceBank.hpp"
#include <SFML/Graphics/Sprite.hpp>

class	Asteroid : public IObject
{
	public:
		Asteroid(void);
		~Asteroid(void) = default;

		void draw(sf::RenderWindow &target, float delta) override;

	private:
		sf::Sprite _sprite;
		float _speed;
		float _rotSpeed;
};

#pragma once

#include "IObject.hpp"
#include "ResourceBank.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <random>

class	Asteroid : public IObject
{
	public:
		Asteroid(void);
		Asteroid(float speed, float rotspeed, sf::Vector2<float> dir, sf::Vector2<float> pos);
		~Asteroid(void) = default;

		void draw(sf::RenderWindow &target, float delta) override;
		static std::unique_ptr<Asteroid> generateRandom(sf::FloatRect sceneBounds);

	private:
		sf::Sprite _sprite;
		float _speed;
		float _rotSpeed;
		sf::Vector2<float> _dir;
};

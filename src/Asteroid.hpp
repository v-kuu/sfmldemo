#pragma once
#include "IObject.hpp"
#include "ResourceBank.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <random>

class	Asteroid : public IObject
{
	public:
		Asteroid(void) = delete;
		Asteroid(sf::FloatRect sceneBounds);
		~Asteroid(void) = default;

		void update(float delta) override;
		void draw(sf::RenderTexture &target) override;
		void getHit(void) override;
		sf::FloatRect hitbox(void) const override;

	private:
		sf::Sprite _sprite;
		float _speed;
		float _rotSpeed;
		sf::Vector2<float> _dir;
		sf::FloatRect _sceneBounds;
		
		void _respawn(void);
};

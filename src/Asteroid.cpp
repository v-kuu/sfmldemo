#include "Asteroid.hpp"

Asteroid::Asteroid(void)
	: _sprite(ResourceBank::textures.find("Asteroid")->second),
	_dc(5, {5.f, 5.f})
{
}

void Asteroid::draw(sf::RenderWindow &target)
{
	sf::Vector2 pos = _sprite.getPosition();
	_sprite.setPosition(pos + sf::Vector2(1.f, 1.f));
	sf::Angle rot = _sprite.getRotation();
	_sprite.rotate(rot + sf::degrees(1));
	target.draw(_sprite);
}

void Asteroid::update(DualComplex &dc)
{
	_dc = dc;
}

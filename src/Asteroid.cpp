#include "Asteroid.hpp"

Asteroid::Asteroid(void)
	: _sprite(ResourceBank::textures.find("Asteroid")->second),
	_speed(100.f),
	_rotSpeed(30.f)
{
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.getCenter());
}

void Asteroid::draw(sf::RenderWindow &target, float delta)
{
	_sprite.move({_speed * delta, _speed * delta});
	_sprite.rotate(sf::degrees(_rotSpeed * delta));
	target.draw(_sprite);
}

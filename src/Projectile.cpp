#include "Projectile.hpp"

Projectile::Projectile(const Player &source)
	: _sprite(ResourceBank::textures.find("Laser")->second)
{
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.getCenter());
	_sprite.setPosition(source.center());
	_velocity = sf::Vector2<float>(0, -1000).rotatedBy(source.orientation());
}

void Projectile::draw(sf::RenderWindow &target, float delta)
{
	_sprite.move(_velocity * delta);
	target.draw(_sprite);
}

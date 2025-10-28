#include "Player.hpp"

Player::Player(sf::FloatRect sceneBounds)
	: _sprite(ResourceBank::textures.find("Player")->second),
	_velocity({0, 0}),
	_orientation(sf::degrees(0)),
	_sceneBounds(sceneBounds),
	_topSpeed(500),
	_fireCooldown(0)
{
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.getCenter());
	_sprite.setPosition(_sceneBounds.getCenter());
}

void Player::draw(sf::RenderWindow &target, float delta)
{
	(void)delta;
	sf::Shader &shader = ResourceBank::shaders["CRT"];
	target.draw(_sprite, &shader);
}

#include <iostream>
bool Player::getHit(sf::FloatRect obj)
{
	if (_sprite.getGlobalBounds().findIntersection(obj) != std::nullopt)
	{
		std::cout << "Ouchie" << std::endl;
		return (true);
	}
	return (false);
}

void Player::update(sf::Vector2<float> accel, sf::Angle rot, float delta)
{
	_orientation += rot;
	_sprite.rotate(rot);
	accel = accel.rotatedBy(_orientation);
	if ((_velocity + accel).length() < _topSpeed)
		_velocity += accel;
	if (_fireCooldown > 0)
		_fireCooldown -= delta;
	_sprite.move(_velocity * delta);
}

void Player::fire(void)
{
	if (_fireCooldown <= 0)
	{
		Projectile::fire(*this);
		_fireCooldown = 1;
	}
}

sf::Vector2<float> Player::center(void) const
{
	return (_sprite.getPosition());
}

sf::Vector2<float> Player::velocity(void) const
{
	return (_velocity);
}

sf::Angle Player::orientation(void) const
{
	return (_orientation);
}

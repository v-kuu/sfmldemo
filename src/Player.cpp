#include "Player.hpp"

Player::Player(sf::FloatRect sceneBounds)
	: _sprite(ResourceBank::textures.find("Player")->second),
	_velocity({0, 0}),
	_orientation(sf::degrees(0)),
	_sceneBounds(sceneBounds),
	_topSpeed(500)
{
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.getCenter());
	_sprite.setPosition(_sceneBounds.getCenter());
}

void Player::draw(sf::RenderWindow &target, float delta)
{
	_sprite.move(_velocity * delta);
	target.draw(_sprite);
}

void Player::update(sf::Vector2<float> accel, sf::Angle rot)
{
	_orientation += rot;
	_sprite.rotate(rot);
	accel = accel.rotatedBy(_orientation);
	if ((_velocity + accel).length() < _topSpeed)
		_velocity += accel;
}

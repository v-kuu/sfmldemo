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

void Player::draw(sf::RenderTexture &target)
{
	target.draw(_sprite);
}

bool Player::getHit(sf::FloatRect obj)
{
	if (_sprite.getGlobalBounds().findIntersection(obj) != std::nullopt)
	{
		std::cout << "Ouchie" << std::endl;
		return (true);
	}
	return (false);
}

void Player::update(float delta)
{
	sf::Angle rot = sf::degrees(0);
	sf::Vector2<float> accel = {0, 0};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		accel += {0, -10};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		accel += {0, 10};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		accel += {-10, 0};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		accel += {10, 0};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		rot += sf::degrees(-5);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		rot += sf::degrees(5);

	_orientation += rot;
	_sprite.rotate(rot);
	accel = accel.rotatedBy(_orientation);
	_velocity += accel;
	if (_velocity.length() > _topSpeed)
		_velocity = _velocity.normalized() * _topSpeed;
	if (_fireCooldown > 0)
		_fireCooldown -= delta;
	_sprite.move(_velocity * delta);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		_fire();
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

void Player::_fire(void)
{
	if (_fireCooldown <= 0)
	{
		Projectile::fire(*this);
		_fireCooldown = 1;
	}
}

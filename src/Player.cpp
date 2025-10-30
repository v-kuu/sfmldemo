#include "Player.hpp"

Player::Player(sf::FloatRect sceneBounds, sf::RenderWindow &window)
	: _window(window),
	_sprite(ResourceBank::textures["Atlas"], ResourceBank::subTextures["Player"]),
	_velocity({0, 0}),
	_orientation(sf::degrees(0)),
	_sceneBounds(sceneBounds),
	_topSpeed(500),
	_fireCooldown(0),
	_hp(5)
{
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.getCenter());
	_sprite.setPosition(_sceneBounds.getCenter());
}

void Player::draw(sf::RenderTexture &target)
{
	target.draw(_sprite);
}

void Player::getHit()
{
	std::cout << "Ouchie" << std::endl;
	_hp--;
	std::cout << "Hp left: " << _hp << std::endl;
	if (_hp <= 0)
		std::cout << "Game over" << std::endl;
}

sf::FloatRect Player::hitbox(void) const
{
	return (_sprite.getGlobalBounds());
}

void Player::update(float delta)
{
	sf::Angle rot = sf::degrees(0);
	sf::Vector2<float> accel = {0, 0};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		accel += {0, -15};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		accel += {0, 15};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		accel += {-15, 0};
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		accel += {15, 0};

	rot = _trackMouse();
	_orientation = rot;
	_sprite.setRotation(rot);
	accel = accel.rotatedBy(_orientation);
	_velocity += accel;
	if (_velocity.length() > _topSpeed)
		_velocity = _velocity.normalized() * _topSpeed;
	if (_fireCooldown > 0)
		_fireCooldown -= delta;
	_sprite.move(_velocity * delta);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		_fire();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
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
		Projectile::fire(_sprite.getPosition(), _orientation, _velocity);
		_fireCooldown = 1;
	}
}

sf::Angle Player::_trackMouse(void)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
	sf::Vector2u winSize = _window.getSize();
	sf::Vector2f center(winSize.x / 2.f, winSize.y / 2.f);

	sf::Vector2f dir = sf::Vector2f(mousePos) - center;
	sf::Vector2f up(0, -1);
	float dot = dir.dot(up);

	float lenDir = sqrtf(static_cast<float>(dir.x * dir.x + dir.y * dir.y));
	if (lenDir == 0.f)
		return (sf::radians(0.f));

	float angle = acosf(dot / static_cast<float>(lenDir * 1.f));
	if (dir.x < 0)
		angle = -angle;

	return (sf::radians(angle));
}

#include "Asteroid.hpp"

Asteroid::Asteroid(void)
	: _sprite(ResourceBank::textures.find("Asteroid")->second),
	_speed(100.f),
	_rotSpeed(30.f),
	_dir({0.5, 0.5})
{
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.getCenter());
}

Asteroid::Asteroid(float speed, float rotspeed, sf::Vector2<float> dir, sf::Vector2<float> pos)
	: _sprite(ResourceBank::textures.find("Asteroid")->second),
	_speed(speed), _rotSpeed(rotspeed), _dir(dir)
{
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.getCenter());
	_sprite.setPosition(pos);
}

void Asteroid::draw(sf::RenderWindow &target, float delta)
{
	_sprite.move(_dir * (_speed * delta));
	_sprite.rotate(sf::degrees(_rotSpeed * delta));
	target.draw(_sprite);
}

std::unique_ptr<Asteroid> Asteroid::generateRandom(sf::FloatRect sceneBounds)
{
	std::random_device rd;
	std::mt19937 rand(rd());
	std::uniform_int_distribution<> speedDist(75, 125);
	std::uniform_int_distribution<> rotSpeedDist(25, 45);
	std::uniform_int_distribution<> sideDist(1, 4);
	std::uniform_int_distribution<> widthDist(0, static_cast<int>(sceneBounds.size.x));
	std::uniform_int_distribution<> heightDist(0, static_cast<int>(sceneBounds.size.y));

	auto speed = static_cast<float>(speedDist(rand));
	auto rotSpeed = static_cast<float>(rotSpeedDist(rand));

	auto side = sideDist(rand);
	sf::Vector2<float> pos(0, 0);
	switch (side)
	{
		case 1:
			pos.x = static_cast<float>(widthDist(rand));
			pos.y = 0;
			break ;
		case 2:
			pos.y = static_cast<float>(heightDist(rand));
			pos.x = 0;
			break ;
		case 3:
			pos.x = static_cast<float>(widthDist(rand));
			pos.y = static_cast<float>(sceneBounds.size.y);
			break ;
		case 4:
			pos.x = static_cast<float>(sceneBounds.size.x);
			pos.y = static_cast<float>(heightDist(rand));
			break ;
		default:
			break ;
	}
	auto dir = sceneBounds.getCenter() - pos;
	dir = dir.normalized();
	std::unique_ptr<Asteroid> ret = std::make_unique<Asteroid>(speed, rotSpeed, dir, pos);
	return (ret);
}

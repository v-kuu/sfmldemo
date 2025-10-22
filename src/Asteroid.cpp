#include "Asteroid.hpp"

Asteroid::Asteroid(sf::FloatRect sceneBounds)
	: _sprite(ResourceBank::textures.find("Asteroid")->second),
	_sceneBounds(sceneBounds)
{
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.getCenter());
	_respawn();
}

void Asteroid::draw(sf::RenderWindow &target, float delta)
{
	_sprite.move(_dir * (_speed * delta));
	_sprite.rotate(sf::degrees(_rotSpeed * delta));
	if (not _sceneBounds.contains(_sprite.getPosition()))
		_respawn();
	target.draw(_sprite);
}

void Asteroid::_respawn(void)
{
	std::random_device rd;
	std::mt19937 rand(rd());
	std::uniform_int_distribution<> speedDist(125, 500);
	std::uniform_int_distribution<> rotSpeedDist(25, 45);
	std::uniform_int_distribution<> sideDist(1, 4);
	std::uniform_int_distribution<> angleDist(-40, 40);
	std::uniform_int_distribution<> widthDist(0, static_cast<int>(_sceneBounds.size.x));
	std::uniform_int_distribution<> heightDist(0, static_cast<int>(_sceneBounds.size.y));

	_speed = static_cast<float>(speedDist(rand));
	_rotSpeed = static_cast<float>(rotSpeedDist(rand));

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
			pos.y = static_cast<float>(_sceneBounds.size.y);
			break ;
		case 4:
			pos.x = static_cast<float>(_sceneBounds.size.x);
			pos.y = static_cast<float>(heightDist(rand));
			break ;
		default:
			break ;
	}
	_sprite.setPosition(pos);
	_dir = (_sceneBounds.getCenter() - pos).normalized();
	_dir = _dir.rotatedBy(sf::degrees(static_cast<float>(angleDist(rand))));
}

std::unique_ptr<Asteroid> Asteroid::generateRandom(sf::FloatRect sceneBounds)
{
	std::unique_ptr<Asteroid> ret = std::make_unique<Asteroid>(sceneBounds);
	return (ret);
}

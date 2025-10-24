#include "Projectile.hpp"

int Projectile::max = 0;
int Projectile::amount = 0;
int Projectile::next = 0;
sf::FloatRect Projectile::_sceneBounds = {};
std::vector<Projectile> Projectile::_projectiles = {};

Projectile::Projectile(void)
	: _sprite(ResourceBank::textures.find("Laser")->second)
{
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.getCenter());
	_despawn();
}

void Projectile::draw(sf::RenderWindow &target, float delta)
{
	_sprite.move(_velocity * delta);
	if (not _sceneBounds.contains(_sprite.getPosition()))
		_despawn();
	target.draw(_sprite);
}

bool Projectile::getHit(sf::FloatRect obj)
{
	(void)obj;
	return (false);
}

void Projectile::drawAll(sf::RenderWindow &target, float delta, Scene &map)
{
	for (auto &it : _projectiles)
	{
		it.draw(target, delta);
		if (it._sprite.getPosition().x > 0)
		{
			for (auto &obj : map.asteroids)
				if (obj.getHit(it._sprite.getGlobalBounds()))
					it._despawn();
		}
	}
}

void Projectile::addProjectile(sf::FloatRect sceneBounds)
{
	_projectiles.emplace_back();
	_sceneBounds = sceneBounds;
	max++;
}

void Projectile::fire(const Player &source)
{
	if (amount >= max)
		return ;
	_projectiles[next]._spawn(source);
	next++;
	if (next == max)
		next = 0;
}

void Projectile::_spawn(const Player &source)
{
	amount++;
	_sprite.setPosition(source.center());
	_sprite.rotate(source.orientation());
	_velocity = sf::Vector2<float>(0, -1000).rotatedBy(source.orientation());
}

void Projectile::_despawn(void)
{
	_sprite.setPosition({-500, -500});
	_velocity = {0, 0};
	_sprite.setRotation(sf::Angle(sf::degrees(0)));
	if (amount > 0)
		amount--;
}

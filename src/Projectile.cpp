#include "Projectile.hpp"

int Projectile::max = 0;
int Projectile::amount = 0;
int Projectile::next = 0;
sf::FloatRect Projectile::_sceneBounds = {};
std::vector<Projectile> Projectile::_projectiles = {};

Projectile::Projectile(void)
	: _sprite(ResourceBank::textures["Laser"])
{
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.getCenter());
	_despawn();
}

void Projectile::update(float delta)
{
	_sprite.move(_velocity * delta);
	if (not _sceneBounds.contains(_sprite.getPosition()))
		_despawn();
}

void Projectile::draw(sf::RenderTexture &target)
{
	target.draw(_sprite);
}

void Projectile::getHit(void)
{
	_despawn();
}

sf::FloatRect Projectile::hitbox(void) const
{
	return (_sprite.getGlobalBounds());
}

bool Projectile::isSpawned(void) const
{
	return (_sprite.getPosition().x > 0);
}

void Projectile::addProjectile(sf::FloatRect sceneBounds)
{
	_projectiles.emplace_back();
	_sceneBounds = sceneBounds;
	max++;
}

void Projectile::fire(sf::Vector2f pos, sf::Angle rot, sf::Vector2f vel)
{
	if (amount >= max)
		return ;
	_projectiles[next]._spawn(pos, rot, vel);
	next++;
	if (next == max)
		next = 0;
}

std::vector<Projectile>& Projectile::projectiles(void)
{
	return (_projectiles);
}

void Projectile::_spawn(sf::Vector2f pos, sf::Angle rot, sf::Vector2f vel)
{
	amount++;
	_sprite.setPosition(pos);
	_sprite.rotate(rot);
	_velocity = sf::Vector2<float>(0, -1000).rotatedBy(rot);
	_velocity += vel;
}

void Projectile::_despawn(void)
{
	_sprite.setPosition({-500, -500});
	_velocity = {0, 0};
	_sprite.setRotation(sf::Angle(sf::degrees(0)));
	if (amount > 0)
		amount--;
}

#pragma once
#include <SFML/Graphics.hpp>

class	IObject
{
	public:
		virtual ~IObject(void) = default;
		virtual void update(float delta) = 0;
		virtual void draw(sf::RenderTexture &target) = 0;
		virtual void getHit() = 0;
		[[nodiscard]] virtual sf::FloatRect hitbox(void) const = 0;
};

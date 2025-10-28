#pragma once

#include <SFML/Graphics.hpp>
#include "DualComplex.hpp"

class	IObject
{
	public:
		virtual ~IObject(void) = default;
		virtual void draw(sf::RenderTexture &target, float delta) = 0;
		virtual bool getHit(sf::FloatRect obj) = 0;
};

#pragma once

#include <SFML/Graphics.hpp>
#include "DualComplex.hpp"

class	IObject
{
	public:
		virtual ~IObject(void) = default;
		virtual void draw(sf::RenderWindow &target, float delta) = 0;
};

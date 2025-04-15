#pragma once
#include <SFML/Graphics.hpp>

class Character
{
public:
	Character() {}
	virtual ~Character() {}

	virtual void movement() {}
	virtual void update() {}
	virtual void draw(sf::RenderWindow& window) {}
};
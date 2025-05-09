#pragma once
#include <SFML/Graphics.hpp>
	
class State
{
public:
	State() {}
	virtual ~State() {}
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};
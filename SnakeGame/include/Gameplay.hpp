#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Snake.hpp"

class Gameplay : public State
{
public:
	Gameplay();

	void init() override;
	void update() override;
	void draw(sf::RenderWindow& window) override;

private:
	Snake m_snake;
};
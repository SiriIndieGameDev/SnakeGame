#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "Snake.hpp"

class SnakeGame
{
public:
	SnakeGame();

	void run();

private:
	void eventHandle();
	void updateAll();
	void windowClear();
	void drawToWindow();
	void displayToWindow();

private:
	sf::RenderWindow m_window;

	Snake m_snake;
};
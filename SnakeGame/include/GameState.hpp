#pragma once
#include "State.hpp"
#include "MainMenu.hpp"

class GameState
{
public:
	static GameState& getInstance();
	~GameState();
	void changeState(State* state);
	void initState();
	void init();
	void update();
	void draw(sf::RenderWindow& window);

private:
	GameState();

private:
	State* m_state;
};
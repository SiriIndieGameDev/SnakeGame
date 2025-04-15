#include "../include/GameState.hpp"

GameState::GameState() : m_state{nullptr}
{
}

GameState& GameState::getInstance()
{
	static GameState instance;
	return instance;
}

GameState::~GameState()
{
	delete m_state;
}

void GameState::changeState(State* state)
{
	if (m_state != nullptr)
	{
		delete m_state;
	}

	m_state = state;
	m_state->init();
}

void GameState::initState()
{
	m_state = new MainMenu();
}

void GameState::init()
{
	m_state->init();
}

void GameState::update() 
{
	m_state->update();
}

void GameState::draw(sf::RenderWindow& window)
{
	m_state->draw(window);
}
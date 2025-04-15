#pragma once
#include "State.hpp"
#include "GameState.hpp"
#include "Gameplay.hpp"

class MainMenu : public State
{
public:
	MainMenu();
	~MainMenu() {}

	void init() override;
	void update() override;
	void draw(sf::RenderWindow& window) override;

private:
	sf::Font m_font;

	sf::Text m_title;
	sf::Text m_play;
	sf::Text m_options;
	sf::Text m_exit;
};
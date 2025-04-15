#pragma once
#include <deque>

#include "Character.hpp"

const int GRID_SIZE = 20;

enum SnakeDirection
{
	UP, DOWN,
	LEFT, RIGHT
};

struct SnakeHead
{
	int x, y;
};

struct SnakeSegments
{
	int x, y;
};

class Snake : public Character
{
public:
	Snake();
	~Snake();

	void fontLoad(std::string fileName);
	void textInit();

	void update() override;
	void windowCollision();
	void itselfCollision();
	void draw(sf::RenderWindow& window) override;

private:
	void spawnApple();
	void movement() override;

private:
	sf::RectangleShape m_snakeHeadShape;
	sf::RectangleShape m_snakeSegmentsShape;
	sf::RectangleShape m_appleShape;
	sf::Vector2i m_applePosition;
	sf::Vector2f m_snakePosition;

	sf::Font m_font;
	sf::Text m_scoreText;

	bool m_isGameOver;
	int m_score;

	int width;
	int height;

	SnakeDirection m_snakeDirection;
	std::deque<SnakeSegments> m_snakeSegment;
};
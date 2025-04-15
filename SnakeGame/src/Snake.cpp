#include <cstdlib>
#include <ctime>

#include "../include/Snake.hpp"

Snake::Snake() : m_snakeDirection(RIGHT), m_font{}, m_scoreText{}, m_isGameOver(false), m_score{}, width(1920), height(1080)
{
	srand(time(NULL));

	fontLoad("youngserif-regular.ttf");
	textInit();

	m_snakeSegment.push_back({10, 10});
	spawnApple();
}

Snake::~Snake()
{}

void Snake::spawnApple()
{
	m_applePosition.x = rand() % (width / GRID_SIZE);
	m_applePosition.y = rand() % (height / GRID_SIZE);
}

void Snake::fontLoad(std::string fileName)
{
	m_font.loadFromFile("res/fonts/" + fileName);
}

void Snake::textInit()
{
	m_scoreText.setFont(m_font);
	m_scoreText.setCharacterSize(20);
	m_scoreText.setFillColor(sf::Color(255, 255, 255));
	m_scoreText.setOutlineColor(sf::Color(0, 0, 0));
	m_scoreText.setOutlineThickness(2);

	m_scoreText.setString("Punkty: " + std::to_string(m_score));
}

void Snake::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_snakeDirection != DOWN)
		m_snakeDirection = UP;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_snakeDirection != UP)
		m_snakeDirection = DOWN;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_snakeDirection != RIGHT)
		m_snakeDirection = LEFT;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_snakeDirection != LEFT)
		m_snakeDirection = RIGHT;
}

void Snake::update()
{
	movement();

	SnakeSegments newSnakeSegment = m_snakeSegment.front();

	switch (m_snakeDirection)
	{
	case UP:
		newSnakeSegment.y--;
		break;
	case DOWN:
		newSnakeSegment.y++;
		break;
	case LEFT:
		newSnakeSegment.x--;
		break;
	case RIGHT:
		newSnakeSegment.x++;
		break;
	}

	windowCollision();
	itselfCollision();

	m_snakeSegment.push_front(newSnakeSegment);

	if (newSnakeSegment.x == m_applePosition.x && newSnakeSegment.y == m_applePosition.y)
	{
		spawnApple();
		m_score++;
		m_scoreText.setString("Punkty: " + std::to_string(m_score));
	}
	else
		m_snakeSegment.pop_back();
}

void Snake::windowCollision()
{
	if (m_snakePosition.x < 0 || m_snakePosition.x >= width / GRID_SIZE ||
		m_snakePosition.y < 0 || m_snakePosition.y >= height / GRID_SIZE)
			m_isGameOver = true;
}

void Snake::itselfCollision()
{

}

void Snake::draw(sf::RenderWindow& window)
{
	m_snakeSegmentsShape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
	m_snakeSegmentsShape.setFillColor(sf::Color(0, 255, 0));
	for (auto &segments : m_snakeSegment)
	{
		m_snakeSegmentsShape.setPosition(segments.x * GRID_SIZE, segments.y * GRID_SIZE);
		window.draw(m_snakeSegmentsShape);
	}

	m_appleShape.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
	m_appleShape.setFillColor(sf::Color(255, 0, 0));
	m_appleShape.setPosition(sf::Vector2f(m_applePosition.x * GRID_SIZE, m_applePosition.y * GRID_SIZE));
	window.draw(m_appleShape);

	window.draw(m_scoreText);
}
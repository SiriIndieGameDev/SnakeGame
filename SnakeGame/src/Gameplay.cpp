#include "../include/Gameplay.hpp"

Gameplay::Gameplay()
{}

void Gameplay::init()
{
	m_snake.fontLoad("youngserif-regular.ttf");
	m_snake.textInit();
}

void Gameplay::update()
{
	m_snake.update();
	m_snake.windowCollision();
	m_snake.itselfCollision();
}

void Gameplay::draw(sf::RenderWindow& window)
{
	m_snake.draw(window);
}
#include "MouseDrawer.h"

MouseDrawer::MouseDrawer()
{
}

MouseDrawer::~MouseDrawer()
{
}

void MouseDrawer::init(sf::RenderWindow* window)
{
}

void MouseDrawer::update(const float& dt)
{
	mouseTrack = sf::Mouse::getPosition();
	std::cout << mouseTrack.x << " " << mouseTrack.x <<"\n";

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		sf::RectangleShape shape;
		shape.setFillColor(sf::Color::Red);
		shape.setSize(sf::Vector2f(25, 25));
		shape.setPosition(sf::Vector2f(mouseTrack.x, mouseTrack.y));
		shapeContain.push_back(shape);
	}
}

void MouseDrawer::draw(sf::RenderTarget* target)
{
	for (int i = 0; i < shapeContain.size(); i++)
	{
		target->draw(shapeContain[i]);
	}
}

#include "DrawInk.h"

DrawInk::DrawInk()
{
}

DrawInk::~DrawInk()
{
}

void DrawInk::init(std::string name, int sizeX, int sizeY, float mouseX, float mouseY)
{
	inkName = name;
	X = mouseX;
	Y = mouseY;

	if (name == "Block")
	{
		shape.setFillColor(sf::Color::Red);
	}
	else
	{
		shape.setFillColor(sf::Color::White);

	}
	
	shape.setSize(sf::Vector2f(sizeX, sizeY));
	shape.setPosition(sf::Vector2f(mouseX, mouseY));
}

void DrawInk::draw(sf::RenderTarget* target)
{
	target->draw(shape);
}

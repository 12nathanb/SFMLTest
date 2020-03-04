#include "DrawInk.h"

DrawInk::DrawInk()
{
}

DrawInk::~DrawInk()
{
}

void DrawInk::init(std::string name, sf::Color c, int sizeX, int sizeY, float mouseX, float mouseY)
{
	inkName = name;
	X = mouseX;
	Y = mouseY;
	color = c;

	shape.setFillColor(c);
	shape.setSize(sf::Vector2f(sizeX, sizeY));
	shape.setPosition(sf::Vector2f(mouseX, mouseY));
}

void DrawInk::draw(sf::RenderTarget* target)
{
	target->draw(shape);
}

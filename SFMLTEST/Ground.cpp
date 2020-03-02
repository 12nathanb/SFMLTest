#include "Ground.h"



Ground::Ground()
{
	
}

Ground::~Ground()
{
}

void Ground::initGround(sf::RenderWindow* window, int height, int width, float x, float y, sf::Color c, std::string temp)
{
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setPosition(sf::Vector2f(x, window->getSize().y - (height + y)));
	this->shape.setFillColor(c);
	this->setTag(temp);

}

const sf::RectangleShape& Ground::getShape() const
{
	return this->shape;
}

void Ground::update(const float& dt)
{
}

void Ground::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

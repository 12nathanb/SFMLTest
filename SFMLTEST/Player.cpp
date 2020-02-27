#include "Player.h"

Player::Player() : Character()
{
	this->shape.setSize(sf::Vector2f(25, 25));
	this->shape.setPosition(sf::Vector2f(100, 100));
	this->shape.setFillColor(sf::Color::White);
}

Player::~Player()
{
}

void Player::isPlayerFalling(bool temp)
{
	falling = temp;
}


void Player::update(const float& dt)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(sf::Vector2f(-10, 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(sf::Vector2f(10, 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		this->move(sf::Vector2f(0, -80));
	}
	

	if (falling)
	{
		canJump = false;
		this->move(sf::Vector2f(0, 10));
	}
	else
	{
		canJump = true;
	}
}

const sf::RectangleShape& Player::getShape() const
{
	return this->shape;
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

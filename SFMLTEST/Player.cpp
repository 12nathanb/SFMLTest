#include "Player.h"

Player::Player() : Character()
{
	this->shape.setSize(sf::Vector2f(100, 100));
	this->shape.setPosition(sf::Vector2f(100, 100));
	this->shape.setFillColor(sf::Color::White);
}

Player::~Player()
{
}



void Player::move(const float& dt, const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
}

void Player::update(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(dt, -10, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(dt, 10, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->move(dt, 0, -10);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->move(dt, 0, 10);
	}
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

#include "Player.h"

Player::Player() : Character()
{
	
	
}

Player::~Player()
{
}

void Player::init(sf::Vector2f v)
{
	this->shape.setSize(sf::Vector2f(25, 25));
	this->shape.setPosition(sf::Vector2f(v.x, v.y));
	this->shape.setFillColor(sf::Color::White);

	std::cout << "Player Spawn: " << v.x << " " << v.y;
}

void Player::isPlayerFalling(bool temp)
{
	falling = temp;
}


void Player::update(const float& dt)
{
	velocity.x = 0;


	if (sf::Joystick::isConnected(0))
	{
		controllerX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		if (controllerX < 15 && controllerX > -15)
		{
			controllerX = 0;
		}

		
		if (sf::Joystick::isButtonPressed(0, 0) && canJump)
		{
			jump();
			
		}

		


		velocity.x += (movementSpeed / 100) * controllerX;
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			velocity.x -= movementSpeed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			velocity.x += movementSpeed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
		{
			jump();
		}
	}
	
	
	
	if (jumping == true)
	{
		velocity.y = jumpVel.y;
	}

	if (this->shape.getPosition().y < maxjumpHeight)
	{
		jumping = false;
		
	}


	if (falling)
	{
		velocity.y += gravity.y;
		canJump = false;
		
	}
	else
	{
		
		if (jumping == false)
		{
			velocity.y = 0;
		}
		
		canJump = true;
	}

	this->move(velocity * dt);
}

void Player::jump()
{
	canJump = false;
	maxjumpHeight = this->shape.getPosition().y - 20;
	std::cout << shape.getPosition().y << "\n";

	jumping = true;
}

const sf::RectangleShape& Player::getShape() const
{
	return this->shape;
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

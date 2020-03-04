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

void MouseDrawer::update(const float& dt, sf::Vector2f posView)
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		DrawInk tile;
		tile.init("Ink",sf::Color::Red, 25, 25, posView.x, posView.y);
		shapeContain.push_back(tile);
	}
}

void MouseDrawer::generateXML()
{
	std::vector<float> xPos;
	std::vector<float> yPos;
	std::vector<sf::Color> color;

	for (int i = 0; i < shapeContain.size(); i++)
	{
		xPos.push_back(shapeContain[i].getX());
		yPos.push_back(shapeContain[i].getY());
		color.push_back(shapeContain[i].getColor());
	}

	std::ofstream file;
	file.open("Level_test1.txt");
	//file << shapeContain.size() << "\n";
	for (int i = 0; i < shapeContain.size(); i++)
	{
		
		file << xPos[i] << " " << yPos[i]  << " " << color[i].toInteger() << "\n";
	}
	file.close();


	

}

void MouseDrawer::draw(sf::RenderTarget* target)
{
	for (int i = 0; i < shapeContain.size(); i++)
	{
		shapeContain[i].draw(target);
	}
}

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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		DrawInk tile;
		tile.init("Block", 25, 25, posView.x, posView.y);
		shapeContain.push_back(tile);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && isThereASpawn == false)
	{
		isThereASpawn = true;
		DrawInk tile;
		tile.init("Spawn", 25, 25, posView.x, posView.y);
		shapeContain.push_back(tile);
	}
}

void MouseDrawer::generateXML()
{
	std::vector<float> xPos;
	std::vector<float> yPos;
	std::vector<std::string> type;

	for (int i = 0; i < shapeContain.size(); i++)
	{
		xPos.push_back(shapeContain[i].getX());
		yPos.push_back(shapeContain[i].getY());
		type.push_back(shapeContain[i].getName());
	}

	std::ofstream file;
	file.open("Level_test1.txt");
	//file << shapeContain.size() << "\n";
	for (int i = 0; i < shapeContain.size(); i++)
	{
		
		file << xPos[i] << " " << yPos[i]  << " " << type[i] << "\n";
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

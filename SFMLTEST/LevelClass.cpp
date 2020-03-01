#include "LevelClass.h"

LevelClass::LevelClass()
{

}

LevelClass::~LevelClass()
{
}

void LevelClass::initLevel(sf::RenderWindow* window)
{
	std::ifstream inFile;
	std::string test;
	
	inFile.open("Level.txt");
	
	if (!inFile)
	{
		std::cout << "Unable to open file";
	}
	else
	{
		//std::cout << "OPEN";
	}

	std::string str((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
	test = str;
	//std::cout << test;
	inFile.close();
	

	int row = 20;
	int col = 10;

	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			std::cout << test[c * r];
			if (test[r * c] == '0')
			{

			}
			else if (test[r * c] == '1')
			{
				std::cout << "Draw";
				Ground groundOBJ;
				groundOBJ.initGround(window, 50, 100, r * 100, c * 100);
				levelFloor.push_back(groundOBJ);
			}
		}
	}


	/*int floorX = 100;
	for (int i = 0; i < floorAmount; i++)
	{
		Ground groundOBJ;
		groundOBJ.initGround(window, 50, 100, floorX * (i + 1), 100 * (i + 1));
		levelFloor.push_back(groundOBJ);
	}

	std::cout << levelFloor.size();*/
}

void LevelClass::updateLevel(const float& dt)
{
}

bool LevelClass::updateCollision(const float& dt, Player& player)
{
	for (int i = 0; i < levelFloor.size(); i++)
	{
		if (player.getShape().getGlobalBounds().intersects(this->levelFloor[i].getShape().getGlobalBounds()))
		{
			return true;
		}
	}

	return false;
}

void LevelClass::renderLevel(sf::RenderTarget* target)
{
	for (int i = 0; i < levelFloor.size(); i++)
	{
		levelFloor[i].render(target);
	}
}

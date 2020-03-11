#include "LevelClass.h"

std::vector<std::string> LevelClass::split(std::string str, char delimiter)
{
	std::vector<std::string> internal;
	std::stringstream ss(str);
	std::string tok;

	while (std::getline(ss, tok, delimiter))
	{
		internal.push_back(tok);
	}
	return internal;
}

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
	std::vector<datas>xV;
	
	
	inFile.open("Level_test1.txt");
	
	std::istream& stream = inFile;
	

	if (!inFile)
	{
		std::cout << "Unable to open file";
	}
	else
	{
		std::cout << "OPEN" << "\n";
	}

	
	if (inFile.is_open())
	{
		

	}

	

	while (std::getline(stream, test))
	{
		datas d;
		std::vector<std::string> testV;
		testV = split(test, ' ');
		
		for (int i = 2; i < testV.size(); i++)
		{
			//std::cout << testV[i - 2] << " " << testV[i - 1] << " " << testV[i] << " " << i << std::endl;

			d.x = std::stof(testV[i - 2]);
			d.y = std::stof(testV[i - 1]);
			d.name = testV[i];

			if (d.name == "Spawn")
			{
				spawnVec.x = d.x;
				spawnVec.y = d.y;
			}

			xV.push_back(d);
		}
	}

	



	int count = 0;

	std::string str;
	


	for (int i = 0; i < xV.size(); i++)
	{
		DrawInk temp;

		temp.init(xV[i].name, 25, 25, xV[i].x, xV[i].y);
		levelFloor.push_back(temp);
		std::cout << xV[i].x << " " << xV[i].y << " " << xV[i].name << "\n";
	}


	
   
	inFile.close();
	
}

void LevelClass::updateLevel(const float& dt)
{
}

bool LevelClass::updateCollision(const float& dt, Player& player)
{
	for (int i = 0; i < levelFloor.size(); i++)
	{
		if (player.getShape().getGlobalBounds().intersects(this->levelFloor[i].getShape().getGlobalBounds()) && this->levelFloor[i].getName() == "Block")
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
		levelFloor[i].draw(target);
	}
}

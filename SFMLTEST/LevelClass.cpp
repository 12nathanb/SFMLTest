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
	
	
	inFile.open("Level_test1.txt");
	
	

	if (!inFile)
	{
		std::cout << "Unable to open file";
	}
	else
	{
		std::cout << "OPEN" << "\n";
	}

	


	
	std::vector<float>xV;
	std::vector<float>yV;
	std::vector<int>cV;


	int count = 0;

	std::string str;
	while (std::getline(inFile, str) )
	{
		float x;
		float y;
		int c;

		std::cout << str << "\n";

		
	}

	/*while (inFile >> x >> y >> c)
	{
		xV.push_back(x);
		yV.push_back(y);
		cV.push_back(c);
	}*/

		

		/*DrawInk temp;
		temp.init("Hello", sf::Color::Red, 25, 25, x[count], y);*/

		/*levelFloor.push_back(temp);*/

	

		
		
	for (int i = 0; i < xV.size(); i++)
	{
		std::cout << xV[i] << " " << yV[i] << " " << cV[i] << "\n";
	}

	

	/*std::string str((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
	test = str;*/
	
   
	inFile.close();
	

	/*for (int i = 0; i < test.size(); i++)
	{
		if (test[i] != '\n')
		{
			LevelTxt.push_back(test[i]);
		}
	}*/

	

	/*int row = 10;
	int col = 20;

	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			std::cout << LevelTxt[r * c];
			if (LevelTxt[c * r] == '0')
			{
				Ground groundOBJ;
				groundOBJ.initGround(window, 50, 50, r * 50, c * 50, sf::Color::Blue, "air");
				levelFloor.push_back(groundOBJ);
			}
			else if (LevelTxt[r * c] == '1')
			{
				
				Ground groundOBJ;
				groundOBJ.initGround(window, 25, 25, r * 30 , c , sf::Color::Red, "floor");
				levelFloor.push_back(groundOBJ);
			}
		}
		std::cout << "\n";
	}*/
}

void LevelClass::updateLevel(const float& dt)
{
}

bool LevelClass::updateCollision(const float& dt, Player& player)
{
	for (int i = 0; i < levelFloor.size(); i++)
	{
		/*if (player.getShape().getGlobalBounds().intersects(this->levelFloor[i].getShape().getGlobalBounds()) && this->levelFloor[i].getTag() == "floor")
		{
			return true;
		}*/
	}

	return false;
}

void LevelClass::renderLevel(sf::RenderTarget* target)
{
	for (int i = 0; i < levelFloor.size(); i++)
	{
		//levelFloor[i].render(target);
	}
}

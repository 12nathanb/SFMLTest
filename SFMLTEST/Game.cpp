#include "Game.h"

void Game::initWindow()
{
	std::ifstream ifs("Config/window.ini");

	std::string title = "None";
	sf::VideoMode window_bounds(800, 600);
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	this->window = new sf::RenderWindow(sf::VideoMode(window_bounds), title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates()
{
	this->states.push(new GameState(this->window));
}

Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

void Game::endApplication()
{
	std::cout << "ENDING";
}

void Game::UpdateDT()
{
	//updates delta time in seconds
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::UpdateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::Update()
{

	this->UpdateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt, this->window);

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		//application ends
		this->endApplication();
		this->window->close();
	}
}

void Game::Render()
{
	//this clears the screen
	this->window->clear();
	//code goes here
	if (!this->states.empty())
	{
		this->states.top()->render();
	}


	//this renders what needs to be rendered
	this->window->display();
}

void Game::Run()
{
	while (this->window->isOpen())
	{
		//updates delta time
		this->UpdateDT();

		//runs update function
		this->Update();
		
		//runs render function
		this->Render();
	}
}

#include "game.hpp"

void Game::Start(void)
{
    if (_gameState != Uninialized)
    {
        return;
    }
    
    _mainWindow.create(sf::VideoMode(640, 480, 32), "Tea");
    
    _gameState = Game::ShowingSplash;
    
    while (!IsExiting())
    {
        GameLoop();
    }
    
    _mainWindow.close();
}

bool Game::IsExiting()
{
    if (_gameState == Game::Exiting)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Game::GameLoop()
{
    sf::Event currentEvent;
    while (_mainWindow.pollEvent(currentEvent))
    {
        switch (_gameState)
        {
            case Game::ShowingMenu:
            {
                ShowMenu();
                break;
            }
                
            case Game::ShowingSplash:
            {
                ShowSplashScreen();
                break;
            }
                
            case Game::Playing:
            {
                _mainWindow.clear(sf::Color(255,0,0));
                _mainWindow.display();
                
                if (currentEvent.type == sf::Event::Closed)
                {
                    _gameState = Game::Exiting;
                }
                
                if (currentEvent.type == sf::Event::KeyPressed)
                {
                    if (currentEvent.key.code == sf::Keyboard::Escape)
                    {
                        ShowMenu();
                    }
                }
                break;
            }
        }
    }
}

void Game::ShowSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.Show(_mainWindow);
    _gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
    MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
    
    switch(result)
    {
        case::MainMenu::Exit:
        {
             _gameState = Game::Exiting;
            break;
        }
            
        case::MainMenu::Play:
        {
            _gameState = Game::Playing;
            break;
        }
           
    }
}

Game::GameState Game::_gameState = Uninialized;
sf::RenderWindow Game::_mainWindow;

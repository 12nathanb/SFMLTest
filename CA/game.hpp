#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"
#include "SplashScreen.hpp"

class Game
{
public:
    static void Start();
    
private:
    static bool IsExiting();
    static void GameLoop();
    
    static void ShowSplashScreen();
    static void ShowMenu();
    
    enum GameState
    {
        Uninialized,
        ShowingSplash,
        Paused,
        ShowingMenu,
        Playing,
        Exiting
    };
    
    static GameState _gameState;
    static sf::RenderWindow _mainWindow;
};

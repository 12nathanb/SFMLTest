#include "SplashScreen.hpp"

void SplashScreen::Show(sf::RenderWindow & window)
{
    sf::Texture image;
    
    if (image.loadFromFile("images/SplashScreen.jpg") != true)
    {
        return;
    }
    
    sf::Sprite sprite(image);
    
    window.draw(sprite);
    window.display();
    
    sf::Event event;
    
    while (true)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::KeyPressed
                || event.type == sf::Event::EventType::MouseButtonPressed
                || event.type == sf::Event::EventType::Closed)
            {
                return;
            }
        }
    }
}

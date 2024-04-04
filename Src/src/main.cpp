#include <SFML/Graphics.hpp>

int main()
{
    // Create the game window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");

    // Game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::Black);
        
        window.display();
    }

    return 0;
}
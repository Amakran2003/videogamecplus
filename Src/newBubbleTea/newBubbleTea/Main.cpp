#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include "bubble.h"
#include "turret.h"
#include "position.h"

using namespace std;
using namespace sf;

float x_Velocity = 0.f;
float y_Velocity = 0.f;

#ifdef _WIN32
float angleInDegrees = 90.0f; // Default angle

void updateAngle() {
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        angleInDegrees -= 0.01f; // Decrease angle when left arrow key is pressed
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        angleInDegrees += 0.01f; // Increase angle when right arrow key is pressed
    }
}

void shotBall() {
    updateAngle();

    if (Keyboard::isKeyPressed(Keyboard::Enter))
    {
        float speed = 1.0f; // Change this to the desired speed

        float angleInRadians = angleInDegrees * 3.14159f / 180.0f;
        x_Velocity = speed * cos(angleInRadians);
        y_Velocity = speed * sin(angleInRadians);

        // Rest of your code...
    }
}
#elif __APPLE__

float angleInDegrees = 90.0f; // Default angle

void updateAngle() {
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        angleInDegrees -= 0.1f; // Decrease angle when left arrow key is pressed
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        angleInDegrees += 0.1f; // Increase angle when right arrow key is pressed
    }
}

void shotBall() {
    updateAngle();

    if (Keyboard::isKeyPressed(Keyboard::Enter))
    {
        float speed = 1.0f; // Change this to the desired speed

        float angleInRadians = angleInDegrees * 3.14159f / 180.f;
        x_Velocity = speed * cos(angleInRadians);
        y_Velocity = speed * sin(angleInRadians);

        // Rest of your code...
    }
}

#else

float angleInDegrees = 90.0f; // Default angle

void updateAngle() {
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        angleInDegrees -= 0.5f; // Decrease angle when left arrow key is pressed
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        angleInDegrees += 0.5f; // Increase angle when right arrow key is pressed
    }
}

void shotBall() {
    updateAngle();

    if (Keyboard::isKeyPressed(Keyboard::Enter))
    {
        float speed = 5.0f; // Change this to the desired speed

        float angleInRadians = angleInDegrees * 3.14159f / 180.f;
        x_Velocity = speed * cos(angleInRadians);
        y_Velocity = speed * sin(angleInRadians);

        // Rest of your code...
    }
}



#endif

void randomColor(Bubble& bubble) {
    srand(time(0));
    int random = rand() % 6 + 1;
    switch (random) {
    case 1:
        bubble.setFillColor(Color::Red);
        break;
    case 2:
        bubble.setFillColor(Color::Green);
        break;
    case 3:
        bubble.setFillColor(Color::Blue);
        break;
    case 4:
        bubble.setFillColor(Color::Yellow);
        break;
    case 5:
        bubble.setFillColor(Color::Magenta);
        break;
    case 6:
        bubble.setFillColor(Color::Cyan);
        break;
    default:
        bubble.setFillColor(Color::White);
        break;
    }
}




int main() {
    RenderWindow window(VideoMode(800, 800), "SFML works!");

    Bubble shotBubble(sf::Color::Cyan, PositionType::ShotBubble_Pos, false);

    Turret turret(MIDDLE_LIMIT - 18, BOTTOM_LIMIT + 80, MIDDLE_LIMIT - 8, BOTTOM_LIMIT - 20, MIDDLE_LIMIT + 8, BOTTOM_LIMIT - 20, MIDDLE_LIMIT + 18, BOTTOM_LIMIT + 80, shotBubble);
    Bubble bubble1(sf::Color::Cyan, PositionType::Row1_Bubble1, false);
    Bubble bubble2(sf::Color::Red, PositionType::Row1_Bubble2, false);
    Bubble bubble3(sf::Color::Yellow, PositionType::Row1_Bubble3, false);
    Bubble bubble4(sf::Color::Green, PositionType::Row1_Bubble4, false);
    Bubble bubble5(sf::Color::Black, PositionType::Row1_Bubble5, false);
    Bubble bubble6(sf::Color::Magenta, PositionType::Row1_Bubble6, false);
    Bubble bubble7(sf::Color::Green, PositionType::Row1_Bubble7, false);
    Bubble bubble8(sf::Color::Cyan, PositionType::Row1_Bubble8, false);
    Bubble bubble9(sf::Color::Blue, PositionType::Row1_Bubble9, false);
    Bubble bubble10(sf::Color::Red, PositionType::Row1_Bubble10, false);
    Bubble bubble11(sf::Color::Cyan, PositionType::Row1_Bubble11, false);
    Bubble bubble12(sf::Color::Red, PositionType::Row1_Bubble12, false);
    Bubble bubble13(sf::Color::Yellow, PositionType::Row1_Bubble13, false);
    Bubble bubble14(sf::Color::Green, PositionType::Row1_Bubble14, false);
    Bubble bubble15(sf::Color::Black, PositionType::Row1_Bubble15, false);
    Bubble bubble16(sf::Color::Magenta, PositionType::Row1_Bubble16, false);
    Bubble bubble17(sf::Color::Green, PositionType::Row1_Bubble17, false);
    Bubble bubble18(sf::Color::Cyan, PositionType::Row1_Bubble18, false);
    Bubble bubble19(sf::Color::Blue, PositionType::Row1_Bubble19, false);
    Bubble bubble20(sf::Color::Red, PositionType::Row1_Bubble20, false);


    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("background.jpg")) {
        // handle error
    }

sf::Sprite background(backgroundTexture);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        window.draw(shotBubble);
        window.draw(bubble1);
        window.draw(bubble2);
        window.draw(bubble3);
        window.draw(bubble4);
        window.draw(bubble5);
        window.draw(bubble6);
        window.draw(bubble7);
        window.draw(bubble8);
        window.draw(bubble9);
        window.draw(bubble10);
        window.draw(bubble11);
        window.draw(bubble12);
        window.draw(bubble13);
        window.draw(bubble14);
        window.draw(bubble15);
        window.draw(bubble16);
        window.draw(bubble17);
        window.draw(bubble18);
        window.draw(bubble19);
        window.draw(bubble20);

        window.draw(turret);   
        window.display();
        

        updateAngle();
        turret.setRotation(angleInDegrees + 90); // +90 because the turret is initially pointing upwards
        
        shotBall(); 

        

        shotBubble.move(x_Velocity, y_Velocity);
        
        if (shotBubble.getPosition().x < 0 || shotBubble.getPosition().x > 800 || shotBubble.getPosition().y < 0 || shotBubble.getPosition().y > 800)
        {
            shotBubble.setPosition(MIDDLE_LIMIT - 10, BOTTOM_LIMIT - 40);
            x_Velocity = 0;
            y_Velocity = 0;


        }


    }

    return 0;
}

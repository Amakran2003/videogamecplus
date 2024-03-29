#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include "Bubble.h"
#include "Turret.h"

using namespace std;
using namespace sf;

float LEFT_LIMIT = 10.f;
float MIDDLE_LIMIT = 400.f;
float RIGHT_LIMIT = 710.f;
float TOP_LIMIT = 10.f;
float BOTTOM_LIMIT = 710.f;

float x_Velocity = 0.f;
float y_Velocity = 0.f;

#ifdef _WIN32
float angleInDegrees = -90.0f; // Default angle

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
#else

float angleInDegrees = -90.0f; // Default angle

void updateAngle() {
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        angleInDegrees -= 1.f; // Decrease angle when left arrow key is pressed
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        angleInDegrees += 1.f; // Increase angle when right arrow key is pressed
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

#endif



int main() {
    RenderWindow window(VideoMode(800, 800), "SFML works!");

    Bubble bubble(sf::Color::Cyan, MIDDLE_LIMIT - 10, BOTTOM_LIMIT - 40);

    Turret turret(MIDDLE_LIMIT - 18, BOTTOM_LIMIT + 80, MIDDLE_LIMIT - 8, BOTTOM_LIMIT - 20, MIDDLE_LIMIT + 8, BOTTOM_LIMIT - 20, MIDDLE_LIMIT + 18, BOTTOM_LIMIT + 80, bubble);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(bubble);
        window.draw(turret);
        window.display();


        shotBall(); 

        bubble.move(x_Velocity, y_Velocity);


    }

    return 0;
}

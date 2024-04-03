#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Bubble.cpp"
#include "Turret.cpp"
#include "Position.cpp"

using namespace std;
using namespace sf;

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

    Bubble bubble(sf::Color::Cyan, PositionType::ShotBubble_Pos, false);

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


        // call random color before showing the bubble

        randomColor(bubble);

        shotBall(); 

        

        bubble.move(x_Velocity, y_Velocity);


    }

    return 0;
}

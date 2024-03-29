#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

float LEFT_LIMIT = 10.f;
float MIDDLE_LIMIT = 400.f;
float RIGHT_LIMIT = 710.f;
float TOP_LIMIT = 10.f;
float BOTTOM_LIMIT = 710.f;

float x_Velocity = 0.f;
float y_Velocity = 0.f;

void shotBall() {
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        x_Velocity = 0.f;
        y_Velocity = -0.5f;
    }
    
}

class Bubble : public CircleShape
{
    public:
        float bubbleRadius = 10.f;
        float thickness = 5.f;
        const Color fillColor;
        const Color outlineColor = Color::Blue;

        // Constructor for ShotBubble
        Bubble(Color f) : fillColor(f) {
            setRadius(bubbleRadius); // Set the radius of the circle shape
            setFillColor(f); // Set the fill color of the circle shape
        }

};



int main() {
    RenderWindow window(VideoMode(800, 800), "SFML works!");
    //CircleShape bubble(10.f);

    Vector2f circlePosition(MIDDLE_LIMIT-10, BOTTOM_LIMIT - 40);

    Bubble bubble(sf::Color::Cyan);

    //bubble.setFillColor(Color::Cyan);
    //bubble.setOutlineThickness(5.f);
    //bubble.setOutlineColor(Color::Blue);

    bubble.setPosition(circlePosition);

    // create an empty shape
    ConvexShape turret;

    // resize it to 5 points
    turret.setPointCount(4);

    turret.setFillColor(Color::Magenta);

    // define the points
    turret.setPoint(0, Vector2f(MIDDLE_LIMIT - 18, BOTTOM_LIMIT + 80));
    turret.setPoint(1, Vector2f(MIDDLE_LIMIT - 8, BOTTOM_LIMIT - 20));
    turret.setPoint(2, Vector2f(MIDDLE_LIMIT + 8, BOTTOM_LIMIT - 20));
    turret.setPoint(3, Vector2f(MIDDLE_LIMIT + 18, BOTTOM_LIMIT + 80));

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

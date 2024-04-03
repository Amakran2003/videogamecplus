#pragma once
#include "SFML/Graphics.hpp"
#include "bubble.h"

class Turret : public sf::ConvexShape {
public:
    int pointCount = 4;
    const sf::Color fillColor = sf::Color::Magenta;

    sf::Vector2f firstPointPos;
    sf::Vector2f secondPointPos;
    sf::Vector2f thirdPointPos;
    sf::Vector2f fourthPointPos;

    Bubble shotBubble; // Declare a member variable of type Bubble

    // Constructor for Turret
    Turret(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, const Bubble& bubbleObj);
    void setRotation(float angle);
};

Turret::Turret(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, const Bubble& bubbleObj)
    : firstPointPos(x0, y0), secondPointPos(x1, y1), thirdPointPos(x2, y2), fourthPointPos(x3, y3),
    shotBubble(bubbleObj) // Initialize the bubble member variable with the provided Bubble object
{
    setPointCount(pointCount);
    setFillColor(fillColor);

    setPoint(0, firstPointPos);
    setPoint(1, secondPointPos);
    setPoint(2, thirdPointPos);
    setPoint(3, fourthPointPos);

    // Set the origin to the top part of the turret
    setOrigin((thirdPointPos.x + secondPointPos.x) / 2, (thirdPointPos.y + secondPointPos.y) / 2);
    setPosition(400,670);
}

void Turret::setRotation(float angle) 
{
    sf::ConvexShape::setRotation(angle);
}

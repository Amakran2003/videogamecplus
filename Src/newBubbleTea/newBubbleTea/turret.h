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
};
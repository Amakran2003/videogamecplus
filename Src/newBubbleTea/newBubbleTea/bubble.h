#pragma once
#include "SFML/Graphics.hpp"
#include "position.h"

class Bubble : public sf::CircleShape {
public:
    float bubbleRadius = 10.f;
    float thickness = 5.f;

    bool exploded = false;

    sf::Vector2f bubblePosition;
    const sf::Color fillColor;
    const sf::Color outlineColor = sf::Color::Blue;

    // Constructor for ShotBubble
    Bubble(sf::Color f, PositionType pos, bool exp);

    sf::Color getBubbleColor();
    void detectCollision(bool detec);
    void disappear(Bubble b);
};

Bubble::Bubble(sf::Color f, PositionType pos, bool exp) : fillColor(f), exploded(exp) {
    setRadius(bubbleRadius);
    setFillColor(f);
    bubblePosition = convert_Pos(pos); // Retrieve position from Position class
    setPosition(bubblePosition);
}

sf::Color Bubble::getBubbleColor() {
    return fillColor;
}
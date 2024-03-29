#pragma once
#include "SFML/Graphics.hpp"

class Bubble : public sf::CircleShape {
public:
    float bubbleRadius = 10.f;
    float thickness = 5.f;

    sf::Vector2f bubblePosition;
    const sf::Color fillColor;
    const sf::Color outlineColor = sf::Color::Blue;

    // Constructor for ShotBubble
    Bubble(sf::Color f, float x, float y);
};

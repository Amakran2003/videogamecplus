#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

#pragma once
class Bubble : public CircleShape
{
public:
    float bubbleRadius = 10.f;
    float thickness = 5.f;

    Vector2f bubblePosition;
    const Color fillColor;
    const Color outlineColor = Color::Blue;

    // Constructor for ShotBubble
    Bubble(Color f, float x, float y) : fillColor(f), bubblePosition(x, y) {
        setRadius(bubbleRadius); // Set the radius of the circle shape
        setFillColor(f); // Set the fill color of the circle shape
        setPosition(bubblePosition);

    }

};

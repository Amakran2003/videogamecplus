#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

#pragma once
class Turret : public ConvexShape
{
    public:
        int pointCount = 4;
        const Color fillColor = Color::Magenta;

        Vector2f firstPointPos;
        Vector2f secondPointPos;
        Vector2f thirdPointPos;
        Vector2f fourthPointPos;

        // Constructor for ShotBubble
        Turret(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3) : firstPointPos(x0, y0), secondPointPos(x1, y1), thirdPointPos(x2, y2), fourthPointPos(x3, y3) {
            setPointCount(pointCount);
            setFillColor(fillColor);

            setPoint(0, firstPointPos);
            setPoint(1, secondPointPos);
            setPoint(2, thirdPointPos);
            setPoint(3, fourthPointPos);

        }

};


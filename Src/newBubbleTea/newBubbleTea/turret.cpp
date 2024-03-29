#include "turret.h"

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
}

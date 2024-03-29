#include "bubble.h"

Bubble::Bubble(sf::Color f, PositionType pos) : fillColor(f) {
    setRadius(bubbleRadius);
    setFillColor(f);
    bubblePosition = convert_Pos(pos); // Retrieve position from Position class
    setPosition(bubblePosition);
}
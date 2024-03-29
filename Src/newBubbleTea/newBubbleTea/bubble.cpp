#include "bubble.h"

Bubble::Bubble(sf::Color f, PositionType pos, bool exp) : fillColor(f), exploded(exp) {
    setRadius(bubbleRadius);
    setFillColor(f);
    bubblePosition = convert_Pos(pos); // Retrieve position from Position class
    setPosition(bubblePosition);
}
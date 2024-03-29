#include "bubble.h"

Bubble::Bubble(sf::Color f, float x, float y) : fillColor(f), bubblePosition(x, y) {
    setRadius(bubbleRadius);
    setFillColor(f);
    setPosition(bubblePosition);
}
#include "Position.h"
#include <SFML/System/Vector2.hpp>

constexpr float LEFT_LIMIT = 10.f;
constexpr float MIDDLE_LIMIT = 400.f;
constexpr float RIGHT_LIMIT = 710.f;
constexpr float TOP_LIMIT = 10.f;
constexpr float BOTTOM_LIMIT = 710.f;

sf::Vector2f getPosition(PositionType type) {
    switch (type) {
    case PositionType::A:
        return sf::Vector2f(RIGHT_LIMIT, BOTTOM_LIMIT);
    case PositionType::B:
        return sf::Vector2f(LEFT_LIMIT, BOTTOM_LIMIT);
    case PositionType::C:
        return sf::Vector2f(RIGHT_LIMIT, TOP_LIMIT);
    case PositionType::D:
        return sf::Vector2f(LEFT_LIMIT, TOP_LIMIT);
    default:
        // Handle invalid position type
        return sf::Vector2f(0.f, 0.f); // or throw an exception
    }
}

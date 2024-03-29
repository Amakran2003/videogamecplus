#include "Position.h"

sf::Vector2f convert_Pos(PositionType type) {
    auto it = positionMap.find(type);
    if (it != positionMap.end()) {
        return it->second;
    }
    else {
        // Handle invalid position type
        return sf::Vector2f(0.f, 0.f); // or throw an exception
    }
}
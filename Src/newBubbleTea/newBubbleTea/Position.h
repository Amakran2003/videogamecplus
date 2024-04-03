#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

#ifndef POSITION_H
#define POSITION_H

constexpr float LEFT_LIMIT = 10.f;
constexpr float MIDDLE_LIMIT = 400.f;
constexpr float RIGHT_LIMIT = 710.f;
constexpr float TOP_LIMIT = 10.f;
constexpr float BOTTOM_LIMIT = 710.f;

enum class PositionType {
    Bottom_Right,
    Bottom_Left,
    Top_Right,
    Top_Left,
    ShotBubble_Pos
};

sf::Vector2f convert_Pos(PositionType type); // Declaration of convert_Pos function

// Define a mapping from PositionType to sf::Vector2f
static const std::unordered_map<PositionType, sf::Vector2f> positionMap = {
    {PositionType::Bottom_Right, sf::Vector2f(RIGHT_LIMIT, BOTTOM_LIMIT)},
    {PositionType::Bottom_Left, sf::Vector2f(LEFT_LIMIT, BOTTOM_LIMIT)},
    {PositionType::Top_Right, sf::Vector2f(RIGHT_LIMIT, TOP_LIMIT)},
    {PositionType::Top_Left, sf::Vector2f(LEFT_LIMIT, TOP_LIMIT)},
    {PositionType::ShotBubble_Pos, sf::Vector2f(MIDDLE_LIMIT - 10, BOTTOM_LIMIT - 40)}
};

#endif

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
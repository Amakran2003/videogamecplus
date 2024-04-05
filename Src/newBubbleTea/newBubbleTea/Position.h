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
    ShotBubble_Pos,
    Row1_Bubble1,
    Row1_Bubble2,
    Row1_Bubble3,
    Row1_Bubble4,
    Row1_Bubble5,
    Row1_Bubble6,
    Row1_Bubble7,
    Row1_Bubble8,
    Row1_Bubble9,
    Row1_Bubble10,
    Row1_Bubble11,
    Row1_Bubble12,
    Row1_Bubble13,
    Row1_Bubble14,
    Row1_Bubble15,
    Row1_Bubble16,
    Row1_Bubble17,
    Row1_Bubble18,
    Row1_Bubble19,
    Row1_Bubble20
};

sf::Vector2f convert_Pos(PositionType type); // Declaration of convert_Pos function

// Define a mapping from PositionType to sf::Vector2f
static const std::unordered_map<PositionType, sf::Vector2f> positionMap = {
    {PositionType::Bottom_Right, sf::Vector2f(RIGHT_LIMIT, BOTTOM_LIMIT)},
    {PositionType::Bottom_Left, sf::Vector2f(LEFT_LIMIT, BOTTOM_LIMIT)},
    {PositionType::Top_Right, sf::Vector2f(RIGHT_LIMIT, TOP_LIMIT)},
    {PositionType::Top_Left, sf::Vector2f(LEFT_LIMIT, TOP_LIMIT)},
    {PositionType::ShotBubble_Pos, sf::Vector2f(MIDDLE_LIMIT - 10, BOTTOM_LIMIT - 40)},
    {PositionType::Row1_Bubble1, sf::Vector2f(LEFT_LIMIT, TOP_LIMIT)},
    {PositionType::Row1_Bubble2, sf::Vector2f(LEFT_LIMIT+40, TOP_LIMIT)},
    {PositionType::Row1_Bubble3, sf::Vector2f(LEFT_LIMIT+40*2, TOP_LIMIT)},
    {PositionType::Row1_Bubble4, sf::Vector2f(LEFT_LIMIT+40*3, TOP_LIMIT)},
    {PositionType::Row1_Bubble5, sf::Vector2f(LEFT_LIMIT+40*4, TOP_LIMIT)},
    {PositionType::Row1_Bubble6, sf::Vector2f(LEFT_LIMIT+40*5, TOP_LIMIT)},
    {PositionType::Row1_Bubble7, sf::Vector2f(LEFT_LIMIT+40*6, TOP_LIMIT)},
    {PositionType::Row1_Bubble8, sf::Vector2f(LEFT_LIMIT+40*7, TOP_LIMIT)},
    {PositionType::Row1_Bubble9, sf::Vector2f(LEFT_LIMIT+40*8, TOP_LIMIT)},
    {PositionType::Row1_Bubble10, sf::Vector2f(LEFT_LIMIT+40*9, TOP_LIMIT)},
    {PositionType::Row1_Bubble11, sf::Vector2f(LEFT_LIMIT+40*10, TOP_LIMIT)},
    {PositionType::Row1_Bubble12, sf::Vector2f(LEFT_LIMIT+40*11, TOP_LIMIT)},
    {PositionType::Row1_Bubble13, sf::Vector2f(LEFT_LIMIT+40*12, TOP_LIMIT)},
    {PositionType::Row1_Bubble14, sf::Vector2f(LEFT_LIMIT+40*13, TOP_LIMIT)},
    {PositionType::Row1_Bubble15, sf::Vector2f(LEFT_LIMIT+40*14, TOP_LIMIT)},
    {PositionType::Row1_Bubble16, sf::Vector2f(LEFT_LIMIT+40*15, TOP_LIMIT)},
    {PositionType::Row1_Bubble17, sf::Vector2f(LEFT_LIMIT+40*16, TOP_LIMIT)},
    {PositionType::Row1_Bubble18, sf::Vector2f(LEFT_LIMIT+40*17, TOP_LIMIT)},
    {PositionType::Row1_Bubble19, sf::Vector2f(LEFT_LIMIT+40*18, TOP_LIMIT)},
    {PositionType::Row1_Bubble20, sf::Vector2f(LEFT_LIMIT+40*19, TOP_LIMIT)}
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
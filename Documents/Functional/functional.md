# BubbleTea Functional Specification

## Table of contents

<details open>
<summary>Table of Contents</summary>

 - [Presentation](#presentation)
   - [Document objective](#-document-objective)
   - [Overview](#-overview)
   - [Goal](#-goal)
   - [Emotions expected](#-emotions-expected)
 - [Game mechanics](#game-mechanics)
   - [Game zone](#-game-zone)
   - [Shooting Turret](#-shooting-turret)
   - [Bubble physics](#-bubble-physics)
   - [Bubble matching](#-bubble-matching)
   - [Blocker progression](#-blocker-progression)
 - [Game rules](#game-rules)
   - [Gameplay Progression](#-gameplay-progression)
   - [Win and lose conditions](#-win-and-lose-conditions)
 - [Implementation details](#implementation-details)
   - [Programming language](#-programming-language)
   - [Frameworks and libraries](#-frameworks-and-libraries)
   - [Input controls](#-input-controls)
</details>

## Presentation

### Document objective

This document provides the functional specifications of the game named BubbleTea that is being made for practicing C++ languages and the SFML framework

### Overview

BubbleTea is a tile-matching puzzle game inspired by the game BubbleShooter, which is itself a clone of the game Puzzle Bobble which was developped by Taito.


### Goal

Players must shoot colored bubbles  from a turret placed at the bottom of the screen to match and clear ranges of bubbles appearing progressively at the top of the screen. 

The game progresses as players aim and shoot bubbles to create clusters of three or more bubbles of the same color, causing them to disappear. 

In fact, the endgame is to avoid any of the appearing bubbles reaching the bottom limit, and to destroy all of them. 

### Emotions expected

To craft an interesting experience, the game wants to trigger several emotions to the player:
- Challenge: the game is quite hard to achieve, giving the player a bit of frustration, but also motivating him to succeed
- Joy: The colored bubbles want to make think of the player that they look like "candies", putting them in a kid dream world
- Relaxation: the game is quite calm and the colored bubbles are appealing, creating a feeling of peace to the user.

## Game mechanics

### Game zone
The game's main interface represents a rectangular area where the player plays and shoots bubbles. Indeed, this is where a prearranged patterns of colored bubbles appears and approaches progressively the bottom of the arena.

### Shooting Turret
At the bottom of the screen, an immovable turret with a cannon is positioned and activated when the player presses a designated input (spacebar, left click, etc...).

Indeed, its role is to allow the player to aim and shoot at the
The player can adjust the angle of the turret using the mouse before shooting.


### Bubble Physics
The shot bubble moves upward, bouncing off the walls until it either collides with a bubble or reaches the top of the screen.

Bubbles disappear upon collision with other bubbles or when they reach the top of the screen.

### Bubble Matching
Before each shot, the color of the shot bubble is randomly selected from a pool of available colors. However, the player can know the color of the next bubble.

To clear the game, the player must destroy the top range of colored bubbles that act as blockers, stopping the upward movement of the shot bubble upon collision.

However, we can destroy them by shooting an existing cluster of at least 2 connected bubbles of the same color than the shot bubble. When hit, the cluster disappear along with the shot bubble.

### Blockers progression
The blocking bubbles cover the whole top of the screen, and more are randomly generated when the player fail to destroy clusters.

Indeed, when the player misses to destroy clusters 3 times in a row, a new row of bubbles is generated on the screen.

Another detail: when the player keep shooting at a specific part of the bottom row of the blockers, he can create a "spike". But if a new row of blockers is generated, an algorithm replaces some bubbles at the bottom to make it flatter.



## Game rules

### Gameplay Progression

A score is displayed when the turret destroy clusters of bubbles. The more bubbles is destroy in one shot, the more points the player will have with a multiplication factor.

Also, the game calculate the full score depending of the game progress and the time used to fulfill the game.

### Win and lose conditions

If the player fail to destroy enough clusters, to the point that the blocking bubbles of the bottom row reach the bottom of the screen, it trigger a Game Over. 

By the way, different colors match different blocking bubbles, and the turrel shoot any color as long as they belong to the blocking ones. 

However, if he manages to destroy all bubbles of the same color, green for example, no more green bubble will be generated neither from the top of the screen and from the turrel.

To win, the player must find the right strategy to destroy the biggest clusters of color possible, destroying color one by one, until one is available. 

FInally, if he destroy the last clusters with the last color, he will have completed the game !

## Implementation Details

### Programming Language

We were imposed to use the C++ language, as we needed to count on Object-Oriented Programming (OOP) and the use of methods and classes for the making of this game.

### Frameworks and libraries

We are using SFML (Simple and Fast Multimedia Library), a low level programming interface written in C++ to provides libraries to make video games or interactive programs.

In fact, we plan to use the 5 pillars of SMFL headers: Graphics, Window, System, Audio and Network.

### Input controls
We use the mouse to adjust the angle of the turret, and its left click to shoot and interact with the interface elements.

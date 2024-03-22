# Bubble Shooter MVP Functional Specification

## Overview
The Bubble Shooter MVP is a simple game where players shoot colored circles from a turret at the bottom of the screen to match and clear bubbles at the top. The game progresses as players aim and shoot bubbles to create clusters of three or more bubbles of the same color, causing them to disappear. This specification outlines the basic functionalities of the game.
Functionalities
## Shooting Mechanism
A circle is shot from the turret positioned at the bottom of the screen when the player presses a designated input (e.g., spacebar).
The player can adjust the angle of the turret using the mouse before shooting.
## Turret Placement
An immovable turret with a cannon is placed at the bottom of the screen.
## Bubble Physics
The shot bubble moves upward, bouncing off the walls until it either collides with a bubble or reaches the top of the screen.
Bubbles disappear upon collision with other bubbles or when they reach the top of the screen.
## Bubble Cluster Formation
When a shot bubble collides with an existing cluster of bubbles of the same color, it attaches to the cluster.
Clusters of three or more bubbles of the same color disappear upon attachment, awarding points to the player.
## Randomization
The color of the shot bubble is randomly selected from a pool of available colors.
## Collision Detection
Bubbles on the top row act as blockers, stopping the upward movement of the shot bubble upon collision.
Bubbles touching the walls of the game screen disappear when a bubble collides with them.
## Bubble Matching
Bubbles of the same color as the shot bubble disappear when hit by it, along with any connected clusters.
## Implementation Details
Language: C++
Graphics Library: SFML (Simple and Fast Multimedia Library)
Input Controls: Keyboard for shooting, mouse for adjusting turret angle.
Physics Engine: Simple collision detection and basic physics for bubble movement and interaction.
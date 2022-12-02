#pragma once

#include "raylib.h"

class Obstacle {
private:
	enum obsType
	{
		lowBird, medBird, highBird, oneCactus, twoCactus, threeCactus
	};
	int speed = 10;
	//Private Variables

	//Screen Variables

public:
	int posX = GetScreenWidth();
	int posY = 0;
	//Public Variables

private:
	//Private Functions

public:
	//Public Functions
	Obstacle(float ScreenWidth, float ScreenHeight, enum obstacleType);
};
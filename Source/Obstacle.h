#pragma once

#include "raylib.h"

class Obstacle {
private:
	int speed = 10;
	//Private Variables

	//Screen Variables

public:
	int posX = GetScreenWidth();
	int posY = 0;
	enum obsType
	{
		lowBird, medBird, highBird, oneCactus, twoCactus, threeCactus
	};
	obsType obs;
	//Public Variables
	Rectangle rec;

private:
	//Private Functions

public:
	//Public Functions
	Obstacle(float ScreenWidth, float ScreenHeight);
	void Spawn();
	void Update();
};
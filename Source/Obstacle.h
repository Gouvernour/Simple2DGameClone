#pragma once

#include "raylib.h"

class Obstacle {
private:
	int speed = 10;
	//Private Variables
	Texture2D birdWingUp;
	Texture2D birdWingDown;
	Texture2D cactusOne;
	Texture2D cactusTwo;
	Texture2D cactusThree;
	bool wingUp = true;
	int AnimationFrequency = 10;
	int AnimationCalled = 0;
	//Screen Variables

public:
	int posX = GetScreenWidth();
	int posY = 0;
	enum obsType
	{
		bird, oneCactus, twoCactus, threeCactus
	};
	obsType obs;
	//Public Variables
	Rectangle rec;

private:
	//Private Functions

public:
	//Public Functions
	Obstacle(float ScreenWidth, float ScreenHeight);
	~Obstacle();
	void Spawn();
	void Update();
	void Draw();
};
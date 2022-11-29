#pragma once

#include "raylib.h"

class Dino {
private:
	//Private Variables
	float JumpHeight;
	float GroundHeight;

public:
	//Public Variables
	Vector2 Position;
	float VerticalPos;

private:
	//Private Functions

public:
	//Public Functions
	Dino(float ScreenWidth, float ScreenHeight);
	~Dino();


	void Jump();
	void Duck();
	float GetHeight();
	Vector2 GetPosition();
};
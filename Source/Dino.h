#pragma once

#include "raylib.h"

class Dino {
private:
	//Private Variables
	float JumpHeight = 50;
	float GroundHeight = 0.0f;
	float JumpSpeed = 4.0f;
	bool IsJumping = false;
	bool IsGrounded = true;
	bool IsDucking = false;
	bool IsFalling = false;
	Vector2 Size = Vector2(20, 40);

	//Screen Variables
	float WindowHeight;
	float WindowWidth;

public:
	//Public Variables
	Vector2 Position = Vector2(40, 200);
	float VerticalPos = 200;

private:
	//Private Functions

public:
	//Public Functions
	Dino(float ScreenWidth, float ScreenHeight);
	~Dino();


	void Jump();
	void Duck();
	void StopDucking();
	float GetHeight();
	Vector2 GetPosition();
	void Draw();
	void Update();
};
#pragma once

#include "raylib.h"

class Dino {
private:
	//Private Variables
	float JumpHeight = 50;
	float JumpSpeed = 8.0f;
	bool IsJumping = false;
	bool IsGrounded = true;
	bool IsDucking = false;
	bool IsFalling = false;
	Vector2 Size = Vector2(40, 80);

	//Animation Variables
	Texture2D Run1;
	Texture2D Run2;
	//
	Texture2D Duck1;
	Texture2D Duck2;
	bool FirstImage = true;
	int AnimationFrequency = 6;
	int AnimationCalled = 0;

	//Screen Variables
	float WindowHeight;
	float WindowWidth;

public:
	float GroundHeight = 0.0f;
	//Public Variables
	Rectangle rec;
	Vector2 Position = Vector2(40, 200);
	float VerticalPos = 200;

private:
	//Private Functions
public:
	//Public Functions
	Dino(float ScreenWidth, float ScreenHeight);
	~Dino();


	bool Jump();
	void Duck();
	void StopDucking();
	float GetHeight();
	Vector2 GetPosition();
	Vector2 GetSize();
	void Draw();
	void Update();
	bool canJump();
};
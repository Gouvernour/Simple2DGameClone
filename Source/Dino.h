#pragma once

#include "raylib.h"

class Dino {
private:
	//Private Variables
	float JumpHeight = 50;
	float GroundHeight = 0.0f;
	float JumpSpeed = 8.0f;
	bool IsJumping = false;
	bool IsGrounded = true;
	bool IsDucking = false;
	bool IsFalling = false;
	Vector2 Size = Vector2(40, 80);

	//Texture2D* Run1;
	//Texture2D* Run2;
	//Texture2D* RunTextures[2] = {Run1, Run2};
	//
	//Texture2D* Duck1;
	//Texture2D* Duck2;
	//Texture2D* DuckTextures[2] = {Duck1, Duck2};

	//Screen Variables
	float WindowHeight;
	float WindowWidth;

public:
	//Public Variables
	Vector2 Position = Vector2(40, 200);
	float VerticalPos = 200;

private:
	//Private Functions
	void Animate();
public:
	//Public Functions
	Dino(float ScreenWidth, float ScreenHeight);
	~Dino();


	void Jump();
	void Duck();
	void StopDucking();
	float GetHeight();
	Vector2 GetPosition();
	Vector2 GetSize();
	void Draw();
	void Update();
};
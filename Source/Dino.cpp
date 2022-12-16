#include "Dino.h"



Dino::Dino(float ScreenWidth, float ScreenHeight)
{
	GroundHeight = ScreenHeight - ScreenHeight/3;
	JumpHeight = GroundHeight - ScreenHeight / 3 + Size.y;
	VerticalPos = GroundHeight;
	WindowHeight = ScreenHeight;
	WindowWidth = ScreenWidth;
	Position = Vector2(40, GroundHeight);
	Duck1 = LoadTexture("./Images/DinoDuck1.png");
	Duck2 = LoadTexture("./Images/DinoDuck2.png");
	Run1 = LoadTexture("./Images/DinoIdle.png");
	Run2 = LoadTexture("./Images/DinoRun2.png");
	FirstImage = true;
	rec.x = GetPosition().x;
	rec.y = GetPosition().y;
	rec.width = GetSize().x;
	rec.height = GetSize().y;
}

Dino::~Dino()
{
	UnloadTexture(Run1);
	UnloadTexture(Run2);
	UnloadTexture(Duck1);
	UnloadTexture(Duck2);
}

bool Dino::Jump()
{
	//Avoid Double Jump
	if (!IsGrounded) 
		return false;


	//Prevent Jumping while ducking or still falling from previous jump
	else if (IsFalling || IsDucking) return false;

	//Enable Jumping
	IsJumping = true;
	IsGrounded = false;

	return true;
}

void Dino::Duck()
{
	//Sets Booleans to represent the player is ducking
	IsDucking = true;
	IsJumping = false;
}

void Dino::StopDucking()
{
	//Sets the player state to not duck anymore
	IsDucking = false;
}

float Dino::GetHeight()
{
	//Getter function for the players current vertical position
	return VerticalPos;
}

Vector2 Dino::GetPosition()
{
	//Getter function for the exact position of Player
	return Position;
}

Vector2 Dino::GetSize()
{
	//Returns the Size of the Player for collision detection
	if (IsGrounded && IsDucking)
	{
		Size = Vector2(140, 40);
	}
	else {
		Size = Vector2(60, 80);
	}
	return Size;
}

void Dino::Draw()
{
	//Draw an animated running

	//Increment Times function has been called to update animation slower than framerate
	AnimationCalled++;
	if (AnimationCalled >= AnimationFrequency)
	{
		//When the Draw function has been called, switch sprite and reset counter
		FirstImage = !FirstImage;
		AnimationCalled = 0;
	}

	//Choose sprite depending on Jump, Duck or Run state and Animation state
	if (!IsGrounded)
	{
		DrawTexture(Run1, Position.x, Position.y, WHITE);
	}
	else if (IsDucking && IsGrounded)
	{
		if (FirstImage)
			DrawTexture(Duck1, Position.x, Position.y, WHITE);
		else
			DrawTexture(Duck2, Position.x, Position.y, WHITE);

	}
	else
	{
		if(FirstImage)
			DrawTexture(Run1, Position.x, Position.y, WHITE);
		else
			DrawTexture(Run2, Position.x, Position.y, WHITE);
	}

}

void Dino::Update()
{
	//update Positions and Collision area
	rec.y = GetPosition().y;
	rec.width = GetSize().x;
	rec.height = GetSize().y;
	if (!IsDucking)					//
		Size = Vector2(40, 80);
	if (IsDucking)
	{
		//Determine if player should fall faster or be grounded
		if (IsGrounded) {
			Position.y = GroundHeight + 40;
		}
		if (Position.y < GroundHeight + 40)
		{
			Position.y += JumpSpeed * 2;
		}
		else if (Position.y >= GroundHeight + 40)
		{
			IsGrounded = true;
			IsFalling = false;
			Position.y = GroundHeight + 40;
		}
	}
	else if(IsFalling)
	{
		//When player start falling decrease height position visually until hit ground
		if (Position.y < GroundHeight)
		{
			Position.y += JumpSpeed;
		}
		else if (Position.y >= GroundHeight)
		{
			IsGrounded = true;
			IsFalling = false;
			Position.y = GroundHeight;
		}
	}
	//Start moving Player upwards while jumping
	else if (IsJumping)
	{
		if (Position.y > JumpHeight)
		{
			Position.y -= JumpSpeed;
		}
		else if (Position.y < JumpHeight)
		{
			IsJumping = false;
			IsFalling = true;
		}
	}
	else if (!IsGrounded)
	{
		if (Position.y < GroundHeight)
		{
			Position.y += JumpSpeed;
		}
		else if (Position.y >= GroundHeight)
		{
			IsGrounded = true;
			IsFalling = false;
			Position.y = GroundHeight;
		}
	}
	else
	{
		//Make sure the player is on groundlevel when in default state
		Position.y = GroundHeight;
		IsGrounded = true;
	}
	VerticalPos = Position.y;
}

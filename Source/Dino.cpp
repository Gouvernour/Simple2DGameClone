#include "Dino.h"

void Dino::Animate()
{
	if (IsGrounded && IsDucking)
	{

	}
	else if (IsGrounded)
	{

	}
	else
	{

	}
}

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
	Rectangle rec;
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

void Dino::Jump()
{
	//Avoid Double Jump
	if (!IsGrounded) return;


	//Prevent Jumping while ducking or still falling from previous jump
	else if (IsFalling || IsDucking) return;

	//Enable Jumping
	IsJumping = true;
	IsGrounded = false;
}

void Dino::Duck()
{
	IsDucking = true;
	IsJumping = false;
}

void Dino::StopDucking()
{
	IsDucking = false;
}

float Dino::GetHeight()
{
	return VerticalPos;
}

Vector2 Dino::GetPosition()
{
	return Vector2();
}

Vector2 Dino::GetSize()
{
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
	AnimationCalled++;
	if (AnimationCalled >= AnimationFrequency)
	{
		FirstImage = !FirstImage;
		AnimationCalled = 0;
	}

	if (!IsGrounded)
	{
		DrawTexture(Duck1, Position.x, Position.y, WHITE);
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
	rec.y = VerticalPos;
	if (!IsDucking)
		Size = Vector2(40, 80);
	if (IsDucking)
	{
		if (IsGrounded) {
			Position.y = GroundHeight + 40;
			rec.width = 80;
			rec.height = 40;
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
	else if (IsJumping)
	{
		if (Position.y > JumpHeight)
		{
			Position.y -= JumpSpeed;
		}
		else if (Position.y <= JumpHeight)
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
		Position.y = GroundHeight;
	}
	VerticalPos = Position.y;
}

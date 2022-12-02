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
}

Dino::~Dino()
{

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
	return Size;
}

void Dino::Draw()
{
	DrawRectangleV(Position, Size, RED);
}

void Dino::Update()
{
	if (!IsDucking)
		Size = Vector2(40, 80);
	if (IsDucking)
	{
		if(IsGrounded)
			Size = Vector2(80, 40);
		if (Position.y < GroundHeight +20)
		{
			Position.y += JumpSpeed * 2;
		}
		else if (Position.y >= GroundHeight + 20)
		{
			IsGrounded = true;
			IsFalling = false;
			Position.y = GroundHeight + 20;
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

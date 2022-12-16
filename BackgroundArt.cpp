#include "BackgroundArt.h"

BackgroundArt::BackgroundArt(float screenWidth, float screenHeight, float groundHeight)
{
	ScreenHeight = screenHeight;
	ScreenWidth = screenWidth;
	GroundHeight = groundHeight;
	Bump = LoadTexture("./Images/DinoDuck1.png");
	Dip = LoadTexture("./Images/DinoDuck2.png");
	Road = LoadTexture("./Images/DinoIdle.png");
	Cloud1 = LoadTexture("./Images/DinoRun2.png");
	Cloud2 = LoadTexture("./Images/DinoRun2.png");
	Star = LoadTexture("./Images/DinoRun2.png");
	Moon = LoadTexture("./Images/DinoRun2.png");
	Sun = LoadTexture("./Images/DinoRun2.png");

	Grounds.push_back(Road);
	Grounds.push_back(Dip);
	Grounds.push_back(Bump);
}

BackgroundArt::~BackgroundArt()
{
}

void BackgroundArt::Draw(bool isNight)
{
	for (int i = 0; i < Grounds.size(); i++)
	{
		DrawTexture(Grounds[i], i * 20, GroundHeight, WHITE);
	}
}

void BackgroundArt::Update()
{
}

#include "BackgroundArt.h"

BackgroundArt::BackgroundArt(float screenWidth, float screenHeight, float groundheight)
{
	ScreenHeight = screenHeight;
	ScreenWidth = screenWidth;
	Bump = LoadTexture("./Images/Bump.png");
	Dip = LoadTexture("./Images/Dip.png");
	Road = LoadTexture("./Images/Road.png");
	Cloud1 = LoadTexture("./Images/Cloud1.png");
	Cloud2 = LoadTexture("./Images/Cloud2.png");
	Star = LoadTexture("./Images/Star.png");
	Moon = LoadTexture("./Images/Moon.png");
	Sun = LoadTexture("./Images/Sun.png");

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
		DrawTexture(Grounds[i], i * 20, 200, WHITE);
	}
}

void BackgroundArt::Update()
{
}

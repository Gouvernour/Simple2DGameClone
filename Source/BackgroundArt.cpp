#include "BackgroundArt.h"

BackgroundArt::BackgroundArt(float screenWidth, float screenHeight, float groundHeight)
{
	ScreenWidth = screenWidth;
	ScreenHeight = screenHeight;
	Bump = LoadTexture("./Images/Bump.png");
	Dip = LoadTexture("./Images/Dip.png");
	Road = LoadTexture("./Images/Road.png");
	Cloud1 = LoadTexture("./Images/Cloud1.png");
	Cloud2 = LoadTexture("./Images/Cloud2.png");
	Sun = LoadTexture("./Images/Sun.png");
	GroundHeight = groundHeight + Road.height * 1.5;

	populateRoad();

}

BackgroundArt::~BackgroundArt()
{
	UnloadTexture(Bump);
	UnloadTexture(Dip);
	UnloadTexture(Road);
	UnloadTexture(Cloud1);
	UnloadTexture(Cloud2);
	UnloadTexture(Star);
	UnloadTexture(Moon);
	UnloadTexture(Sun);
}

void BackgroundArt::populateRoad()
{
	if (GroundLocations.size() < 1)
	{
		GroundLocations.push_back(Vector2(0, GroundHeight));
		Grounds.push_back(Road);
	}
	while (GroundLocations.back().x < ScreenWidth * 2)
	{
		switch (GetRandomValue(1, 20))
		{
		case 19:
			GroundLocations.push_back(Vector2(GroundLocations.back().x + Grounds.back().width, GroundHeight));
			GroundLocations.push_back(Vector2(GroundLocations.back().x, GroundHeight + Road.height - (Dip.height/2.5)));
			Grounds.push_back(Dip);
			Grounds.push_back(Dip);
		case 20:
			GroundLocations.push_back(Vector2(GroundLocations.back().x + Grounds.back().width, GroundHeight - (Bump.height/1.5)));
			GroundLocations.push_back(Vector2(GroundLocations.back().x, GroundHeight - Bump.height + Road.height));
			Grounds.push_back(Bump);
			Grounds.push_back(Bump);
		default:
			GroundLocations.push_back(Vector2(GroundLocations.back().x + Grounds.back().width, GroundHeight));
			Grounds.push_back(Road);
			break;
		}
	}
}

void BackgroundArt::Draw(bool isNight)
{
	for (int i = 0; i < Grounds.size(); i++)
	{
		DrawTexture(Grounds[i], GroundLocations[i].x, GroundLocations[i].y, WHITE);
	}
}

void BackgroundArt::Update(float runSpeed)
{
	for (int i = 0; i < Grounds.size(); i++)
	{
		GroundLocations[i].x -= runSpeed;
		if (GroundLocations[i].x + Grounds[i].width < 0)
		{
			DeleteIndexes.push_back(i);
		}
	}
	for (int i = DeleteIndexes.size() - 1; i > 0; i--)
	{
 		GroundLocations.erase(GroundLocations.begin() + DeleteIndexes[i]);
		Grounds.erase(Grounds.begin() + DeleteIndexes[i]);
		AddRoadPiece();
	}
	DeleteIndexes.clear();

}

void BackgroundArt::AddRoadPiece()
{
	while (GroundLocations.back().x < ScreenWidth * 2)
	{
		switch (GetRandomValue(1, 20))
		{
		case 19:
			GroundLocations.push_back(Vector2(GroundLocations.back().x + Grounds.back().width, GroundHeight));
			GroundLocations.push_back(Vector2(GroundLocations.back().x, GroundHeight + Road.height - (Dip.height / 2.5)));
			Grounds.push_back(Dip);
			Grounds.push_back(Dip);
		case 20:
			GroundLocations.push_back(Vector2(GroundLocations.back().x + Grounds.back().width, GroundHeight - (Bump.height / 1.5)));
			GroundLocations.push_back(Vector2(GroundLocations.back().x, GroundHeight - Bump.height + Road.height));
			Grounds.push_back(Bump);
			Grounds.push_back(Bump);
		default:
			GroundLocations.push_back(Vector2(GroundLocations.back().x + Grounds.back().width, GroundHeight));
			Grounds.push_back(Road);
			break;
		}
	}
}

#include "BackgroundArt.h"

BackgroundArt::BackgroundArt(float screenWidth, float screenHeight, float groundHeight)
{
	//Set Variables and load textures
	ScreenWidth = screenWidth;
	ScreenHeight = screenHeight;
	Bump = LoadTexture("./Images/Bump.png");
	Dip = LoadTexture("./Images/Dip.png");
	Road = LoadTexture("./Images/Road.png");
	Cloud1 = LoadTexture("./Images/Cloud1.png");
	Cloud2 = LoadTexture("./Images/Cloud2.png");
	GroundHeight = groundHeight + Road.height * 1.5;

	populateRoad();
	populateBackgrounds();
}

BackgroundArt::~BackgroundArt()
{
	//Unload all memory that has been allocated
	UnloadTexture(Bump);
	UnloadTexture(Dip);
	UnloadTexture(Road);
	UnloadTexture(Cloud1);
	UnloadTexture(Cloud2);
	Clouds.clear();
	Grounds.clear();
	CloudLocations.clear();
	GroundLocations.clear();
}

void BackgroundArt::populateRoad()
{
	//Make sure first ground piece is instantiated
	if (GroundLocations.size() < 1)
	{
		GroundLocations.push_back(Vector2(0, GroundHeight));
		Grounds.push_back(Road);
	}
	//Populating the rest of the road randomising between 3 different sprites
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

void BackgroundArt::populateBackgrounds()
{
	//Add Clouds to the screen
	AddCloud();
	CloudLocations[0].x = 80;
	AddCloud();
	CloudLocations[1].x = 180;
	AddCloud();
	CloudLocations[2].x = 300;
}

void BackgroundArt::Draw(bool isNight)
{
	//Draw the road and clouds where they are located
	for (int i = 0; i < Grounds.size(); i++)
	{
		DrawTexture(Grounds[i], GroundLocations[i].x, GroundLocations[i].y, WHITE);
	}
	for (int i = 0; i < Clouds.size(); i++)
	{
		DrawTexture(Clouds[i], CloudLocations[i].x, CloudLocations[i].y, WHITE);
	}
}

void BackgroundArt::Update(float runSpeed)
{
	//Update location of all roadpieces and clouds and delete out of bounds objects, and add a new one to replace the destroyed one
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
	for (int i = Clouds.size()-1; i >= 0; i--)
	{
		CloudLocations[i].x -= runSpeed / 4;
		if (CloudLocations[i].x + Clouds[i].width < 0)
		{
			Clouds.erase(Clouds.begin() + i);
			CloudLocations.erase(CloudLocations.begin() + i);
		}
	}
	//Check to make sure there is not too many clouds on screen
	if (Clouds.size() < 3)
		AddCloud();
}

void BackgroundArt::AddRoadPiece()
{
	//Randomly Chooses a ground piece weighted towards regular roads
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

void BackgroundArt::AddCloud()
{
	//Randomly create different cloud and a random location for clouds weighted towards cloud2 and cloud1 have a larger difference in location for occasional greater distance between clouds
	switch (GetRandomValue(1,4))
	{
	case 1:
		Clouds.push_back(Cloud1);
		CloudLocations.push_back(Vector2(ScreenWidth + GetRandomValue(10, 1000), ScreenHeight - GetRandomValue(GroundHeight - 20, GroundHeight - 150)));
	default:
		Clouds.push_back(Cloud2);
		CloudLocations.push_back(Vector2(ScreenWidth + GetRandomValue(10, 100), ScreenHeight - GetRandomValue(GroundHeight - 20, GroundHeight - 200)));
		break;
	}
}

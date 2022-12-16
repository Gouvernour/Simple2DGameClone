#include "Obstacle.h"

Obstacle::Obstacle(float screenWidth, float screenHeight)
{
	birdWingUp = LoadTexture("./Images/birdWingUp.png");
	birdWingDown = LoadTexture("./Images/birdWingDown.png");
	cactusOne = LoadTexture("./Images/oneCactus.png");
	cactusTwo = LoadTexture("./Images/twoCactus.png");
	cactusThree = LoadTexture("./Images/threeCactus.png");
}

Obstacle::~Obstacle() {
	UnloadTexture(birdWingDown);
	UnloadTexture(birdWingUp);
	UnloadTexture(cactusOne);
	UnloadTexture(cactusTwo);
	UnloadTexture(cactusThree);
}

void Obstacle::Spawn() {
	//spawn an obstacle of the given type at the default posX (should be equal to screen width) and posY dependent on the obstacle type
	switch (GetRandomValue(1, 6))
	{
	case 1:
		obs = bird;
		posY = GetScreenHeight() - (GetScreenHeight() / 3);
		rec.width = 40;
		rec.height = 40;
		break;
	case 2:
		obs = bird;
		posY = (GetScreenHeight() - (GetScreenHeight() / 3)) - 50;
		rec.width = 40;
		rec.height = 40;
		break;
	case 3:
		obs = bird;
		posY = (GetScreenHeight() - (GetScreenHeight() / 3)) - 110;
		rec.width = 40;
		rec.height = 40;
		break;
	case 4:
		obs = oneCactus;
		posY = GetScreenHeight() - (GetScreenHeight() / 3);
		rec.width = 32;
		rec.height = 65;
		break;
	case 5:
		obs = twoCactus;
		posY = GetScreenHeight() - (GetScreenHeight() / 3);
		rec.width = 64;
		rec.height = 80;
		break;
	case 6:
		posY = GetScreenHeight() - (GetScreenHeight() / 3);
		obs = threeCactus;
		rec.width = 88;
		rec.height = 80;
		break;
	default:
		break;
	}
	rec.y = posY;
	posX = GetScreenWidth() + GetRandomValue(1, 150);
	rec.x = posX;
}

void Obstacle::Update() {
	//update
	posX -= obsSpeed;
	rec.x = posX;
	if (posX < 0) {
		Spawn();
	}
}

void Obstacle::Draw() {

	if (obs == bird) {
		AnimationCalled++;
		if (AnimationCalled >= AnimationFrequency)
		{
			wingUp = !wingUp;
			AnimationCalled = 0;
		}
	}


	switch (obs)
	{
	case Obstacle::bird:
		if (wingUp) {
		DrawTexture(birdWingUp, posX, posY, WHITE);
		}
		else {
		DrawTexture(birdWingDown, posX, posY, WHITE);
		}
		break;
	case Obstacle::oneCactus:
		DrawTexture(cactusOne, posX, posY, WHITE);
		break;
	case Obstacle::twoCactus:
		DrawTexture(cactusTwo, posX, posY, WHITE);
		break;
	case Obstacle::threeCactus:
		DrawTexture(cactusThree, posX, posY, WHITE);
		break;
	default:
		break;
	}
}
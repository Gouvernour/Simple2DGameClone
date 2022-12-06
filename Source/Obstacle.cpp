#include "Obstacle.h"

Obstacle::Obstacle(float screenWidth, float screenHeight)
{
	
}

void Obstacle::Spawn() {
	//spawn an obstacle of the given type at the default posX (should be equal to screen width) and posY dependent on the obstacle type
	switch (GetRandomValue(1, 6))
	{
	case 1:
		obs = lowBird;
		posY = GetScreenHeight() - (GetScreenHeight() / 3);
		break;
	case 2:
		obs = medBird;
		posY = (GetScreenHeight() - (GetScreenHeight() / 3)) - 50;
		break;
	case 3:
		obs = highBird;
		posY = (GetScreenHeight() - (GetScreenHeight() / 3)) - 110;
		break;
	case 4:
		obs = oneCactus;
		posY = GetScreenHeight() - (GetScreenHeight() / 3);
		break;
	case 5:
		obs = twoCactus;
		posY = GetScreenHeight() - (GetScreenHeight() / 3);
		break;
	case 6:
		posY = GetScreenHeight() - (GetScreenHeight() / 3);
		obs = threeCactus;
		break;
	default:
		break;
	}
	rec.y = posY;
	posX = GetScreenWidth() + GetRandomValue(1, 150);
	rec.x = posX;
	rec.width = 60;
	rec.height = 80;
}

void Obstacle::Update() {
	//update
	posX -= speed;
	rec.x = posX;
	if (posX < 0) {
		Spawn();
	}
}

void Obstacle::Draw() {
	DrawRectangle(rec.x, rec.y, rec.width, rec.height, RED);
}
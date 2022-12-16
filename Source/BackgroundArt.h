#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std;

class BackgroundArt {
	Texture2D Road;
	Texture2D Bump;
	Texture2D Dip;
	Texture2D Sun;
	Texture2D Moon;
	Texture2D Star;
	Texture2D Cloud1;
	Texture2D Cloud2;

	vector<Texture2D> Grounds;
	vector<Texture2D> Clouds;
	vector<Vector2> GroundLocations;
	vector<Vector2> CloudLocations;
	vector<int> DeleteIndexes;

	float ScreenWidth;
	float ScreenHeight;
	float GroundHeight;
	Vector2 SunLocation;
	void populateRoad();
	void populateBackgrounds();
	void AddRoadPiece();
	void AddCloud();

public:
	BackgroundArt(float screenWidth, float screenHeight, float groundHeight);
	~BackgroundArt();


	void Draw(bool isNight);
	void Update(float runSpeed);
};
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
	vector<Texture2D> Backgrounds;

	float ScreenWidth;
	float ScreenHeight;

public:
	BackgroundArt(float ScreenWidth, float ScreenHeight);
	~BackgroundArt();

	void Draw(bool isNight);
	void Update();
	void AddRoadPiece();
	void AddBackgroundPiece();
};
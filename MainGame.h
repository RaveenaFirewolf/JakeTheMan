#pragma once
#include "Background.h"
#include "Player.h"
class MainGame
{
public:
	MainGame(float posX, float posY);

	void Update(int frame);
	void Draw(RenderWindow* window);
	
private:
	Font* mFont;
	Text mScore;

	Font* mFont2;
	Text mTime;

	int scores;
};
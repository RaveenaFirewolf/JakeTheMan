#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "MainGame.h"

MainGame::MainGame(float posX, float posY)
{
	mFont = new Font();
	mFont->loadFromFile("fonts/cour.ttf");

	scores = 0;

	stringstream str;
	str << scores;

	mScore.setFont(*mFont);
	mScore.setString("Score: " + to_string(scores));
	mScore.setCharacterSize(36);
	mScore.setFillColor(Color(255, 255, 255));
	mScore.setOutlineColor(Color(0, 0, 0));
	mScore.setOutlineThickness(3.0f);
	mScore.setPosition(posX, posY);

	mFont2 = new Font();
	mFont2->loadFromFile("Fonts/MetalMacabre.ttf");

	mTime.setFont(*mFont2);
	mTime.setString("Timer: ");
	mTime.setCharacterSize(32);
	mTime.setFillColor(Color(255, 255, 255));
	mTime.setOutlineColor(Color(0, 0, 0));
	mTime.setOutlineThickness(3.0f);
	mTime.setPosition(0.0f, 50.0f);
}

void MainGame::Update(int frame)
{
	frame++;
	if (frame % 20)
	{
		scores++;
	}
}

void MainGame::Draw(RenderWindow* window)
{
	window->draw(mScore);
	window->draw(mTime);
}
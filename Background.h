#pragma once
#include "Player.h"
class Background
{
public:
	Background();

	void Draw(RenderWindow* window);
	
private:
	sf::RectangleShape rect;
	sf::RectangleShape rect2;
	sf::RectangleShape rect3;
	Texture playerTexture;
	Texture texture[5];
	Texture* tilesTex;
	Texture enemyTex[2];

	Sprite tiles;
	Sprite player;
	Sprite enemy[2];
	Sprite sprite[5];
};
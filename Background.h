#pragma once
#include "Player.h"

const int MAX_LADDER_NUMBER = 8;

class Background
{
public:
	Background(RenderWindow* window);

	Player player;

	bool Collision(Sprite &sprite);
	void Draw(RenderWindow* window);

	Sprite ladder;
	
private:
	sf::RectangleShape rect;
	sf::RectangleShape rect2;
	sf::RectangleShape rect3;
	Texture playerTexture;
	Texture texture[5];
	Texture* tilesTex;
	Texture enemyTex[2];
	Texture ladderTex;

	Sprite tiles;
	Sprite playerSprite;
	Sprite enemy[2];
	Sprite sprite[5];
};
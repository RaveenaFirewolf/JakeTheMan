#pragma once
#include "Variables.h"

class Player
{
public:
	Player();

	bool isJumping(bool isJump) { return isJump; }
	void Movement(float dt);
	void Draw(sf::RenderWindow* window);

private:
	// Player images
	Texture playerTex;
	Sprite playerSprite;

	Vector2f playerPosition;
	Vector2f velocity;

	// Player variable in the game
	int hp;
	int hpMax;

	// Player movement variable
	Clock clock;

	float dt;
	float moveSpeed;
	float jumpSpeed;
	float gravitySpeed;

	//Player flags is player somewhere on the game
	bool onGround;
	bool isJump;

	// Camera view
	Vector2f viewPosition;

	// Game timing
	//Clock clock;
	View view;

	// Ground variable
	float groundHeight;
	float groundWidth;
};


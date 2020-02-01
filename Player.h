#pragma once
#include "Variables.h"

class Player
{
public:
	Player();

	void Movement();
	void Draw(sf::RenderWindow* window);
	bool GetJumpState(bool isJump) { return isJump; }
	
private:
	sf::Texture playerTex;
	sf::Sprite playerSprite;

	Vector2f playerPosition;

	float moveSpeed = 4.0f;
	float jumpSpeed = 7.0f;
	float gravitySpeed = 0.7f;

	float groundHeight = 570.0f;
	float groundWidth = 742.0f;
	
	bool onGround;
	bool isJump;
	sf::Vector2f velocity;
};


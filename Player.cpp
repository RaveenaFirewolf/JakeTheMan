#include "Player.h"

Player::Player()
{
	playerTex.loadFromFile("Gfx/Player.png");

	playerSprite.setTexture(playerTex);
	playerSprite.setScale(1.2f, 1.2f);
	playerSprite.setPosition(50.0f, 555.0f);

	velocity = sf::Vector2f(sf::Vector2f(0.0f, 0.0f));
	viewPosition = sf::Vector2f(0.0f, 0.0f);
	
	gravitySpeed = 4.0f;
	moveSpeed = 4.0f;
	jumpSpeed = 4.0f;
	// GroundHeight = 380f
	groundHeight = 100.0f;
	onGround = true;
	isJump = false;

	hp = 10;
	hpMax = 100;

	view.reset(FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	view.setViewport(FloatRect(0, 0, 1.0f, 1.0f));
}

void Player::Movement(float dt)
{
	// Player movement
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		playerSprite.move(-moveSpeed * dt, 0.0f);
	}

	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		playerSprite.move(moveSpeed * dt, 0.0f);
	}

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		playerSprite.move(0.0f, -moveSpeed * dt);

		if (onGround == false)
		{
			playerSprite.move(0.0f, gravitySpeed + 1.0f);
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		playerSprite.move(0.0f, moveSpeed * dt);
	}

	// If a player is above the ground and there isn't a jump 
	if (playerSprite.getPosition().y < groundHeight && isJump == false)
	{
		playerSprite.move(sf::Vector2f(0.0f, gravitySpeed * dt));
	}

	// Gravity
	if (playerSprite.getPosition().y < groundHeight && isJump == false)
	{
		playerSprite.move(0.0f, gravitySpeed * dt);
	}

	viewPosition.x = playerSprite.getPosition().x + 40 - (SCREEN_WIDTH / 2);
	viewPosition.y = playerSprite.getPosition().y + 40 - (SCREEN_HEIGHT);

	if (viewPosition.x < 0)
	{
		viewPosition.x = 0;
	}
	if (viewPosition.y < 0)
	{
		viewPosition.y = 0;
	}

	view.reset(sf::FloatRect(viewPosition.x, viewPosition.y, SCREEN_WIDTH, SCREEN_HEIGHT));
}

void Player::Draw(RenderWindow *window)
{
	window->draw(playerSprite);
	window->setView(view);
	//window->draw(playerSprite);
}
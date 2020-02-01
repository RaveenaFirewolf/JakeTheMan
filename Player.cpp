#include "Player.h"

Player::Player()
{
	playerTex.loadFromFile("Gfx/Player.png");

	playerSprite.setTexture(playerTex);
	playerSprite.setScale(1.0f, 1.0f);
	playerSprite.setPosition(50.0f, 500.0f);

	velocity = sf::Vector2f(sf::Vector2f(0.0f, 0.0f));

	onGround = true;
	isJump = false;
}

void Player::Movement()
{
	// Player movement
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		playerSprite.move(-moveSpeed, 0.0f);
	}

	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		playerSprite.move(moveSpeed, 0.0f);
		if (playerSprite.getPosition().x + 40 > 742 && playerSprite.getPosition().x + 40 < 808)
		{
			onGround = false;
		}
	}

	if ((playerSprite.getPosition().x + 40 > 809 && playerSprite.getPosition().x + 40 < 1130) && (playerSprite.getPosition().y <= 424))
	{
		playerSprite.setPosition(playerSprite.getPosition().x, 424.0f);
		onGround = true;
	}

	if (onGround == false)
	{
		playerSprite.move(0.0f, gravitySpeed + 1.0f);
		if (playerSprite.getPosition().y > SCREEN_HEIGHT)
		{
			cout << "You died!\n";

			// Show the player in to the begining of the game
			playerSprite.setPosition(50.0f, 500.0f);
			onGround = true;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		playerSprite.move(0.0f, -moveSpeed);
		// x = 66, y = 254
		//808 + 32
		if (playerSprite.getPosition().y >= 200)
		{
			playerSprite.setPosition(809.0f, 250.0f);
			onGround = true;
		}

	}


	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		GetJumpState(true);
	}

	// If a player is above the ground and there isn't a jump 
	if (playerSprite.getPosition().y < groundHeight && isJump == false)
	{
		playerSprite.move(sf::Vector2f(0.0f, gravitySpeed));
	}
}

void Player::Draw(RenderWindow *window)
{
	window->draw(playerSprite);
}
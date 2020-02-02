#pragma once
#include "Background.h"
#include "Player.h"
class MainGame
{
public:
	MainGame(float posX, float posY);
	
	Player player;

	bool IsPlayerJump(Player player, bool isJump) { return player.isJumping(isJump); }
	void Update(float dt);

	// TODO: Game UI
	void Draw(RenderWindow* window);
	
private:
	Clock clock;
	Font* mFont;
	Text mScore;

	Font* mFont2;
	Text mTime;

	int scores;
};
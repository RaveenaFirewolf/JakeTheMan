#include "Background.h"

Background::Background(RenderWindow *window)
{
	/*rect.setPosition(sf::Vector2f(0.0f, 635.0f));
	rect.setSize(sf::Vector2f(740.0f, 90.0f));
	rect.setFillColor(sf::Color(0, 255, 0));

	rect2.setPosition(sf::Vector2f(810.0f, 450.0f));
	rect2.setSize(sf::Vector2f(321.0f, 73.0f));
	rect2.setFillColor(sf::Color(0, 255, 0));*/

	texture[0].loadFromFile("Gfx/Bg.png");
	sprite[0].setTexture(texture[0]);
	sprite[0].setPosition(Vector2f(0.0f, 0.0f));
	sprite[0].setScale(5.0f, 5.0f);

	texture[1].loadFromFile("Gfx/Mountain.png");
	sprite[1].setTexture(texture[1]);
	sprite[1].setPosition(Vector2f(0.0f, 0.0f));
	sprite[1].setScale(5.0f, 5.0f);

	texture[2].loadFromFile("Gfx/bgMountains.png");
	sprite[2].setTexture(texture[2]);
	sprite[2].setPosition(Vector2f(0.0f, 0.0f));
	sprite[2].setScale(5.0f, 5.0f);

	texture[3].loadFromFile("Gfx/MountainTrees.png");
	sprite[3].setTexture(texture[3]);
	sprite[3].setPosition(Vector2f(0.0f, 0.0f));
	sprite[3].setScale(5.0f, 5.0f);

	texture[4].loadFromFile("Gfx/Bg01.png");
	sprite[4].setTexture(texture[4]);
	sprite[4].setPosition(Vector2f(0.0f, 0.0f));
	sprite[4].setScale(2.0f, 2.0f);

	tilesTex = new Texture();
	tilesTex->loadFromFile("Tiles.png");
	
	tiles.setTexture(*tilesTex);
	tiles.setPosition(Vector2f(64.0f, 656.0f));
	tiles.setTextureRect(IntRect(0, 0, 64, 64));
	tiles.setScale(2.0f, 2.0f);

	enemyTex[0].loadFromFile("Gfx/Bee.png");
	enemy[0].setTexture(enemyTex[0]);
	enemy[0].setPosition(sf::Vector2f(0.0f, 0.0f));

	enemyTex[1].loadFromFile("Gfx/Bee2.png");
	enemy[1].setTexture(enemyTex[1]);
	enemy[1].setPosition(sf::Vector2f(0.0f, 0.0f));
	enemy[0].move(0.0f, -2.0f);

	// Loading the ladder texture to the memory
	ladderTex.loadFromFile("Gfx/Drabina.png");

	ladder.setTexture(ladderTex);
	ladder.setPosition(sf::Vector2f(735.0f, 450.0f));
	ladder.setScale(sf::Vector2f(1.0f, 1.0f));
}

bool Background::Collision(Sprite &sprite)
{
	// If there is a collision return true;
	// else return false;
	if (playerSprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
	{
		cout << "There is a collision!\n";
		return true;
	}

	cout << "There is not a collision!\n";
	return false;
}

void Background::Draw(RenderWindow* window)
{
	for (int i = 0; i < 5; i++)
	{
		window->draw(sprite[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		window->draw(enemy[i]);
	}

	window->draw(ladder);

	window->draw(rect);
	window->draw(rect2);
}
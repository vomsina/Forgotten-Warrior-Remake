#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;


class GameOver
{
public:
	Image gameoverImage;
	Texture gameoverTex;
	Sprite gameover;
	
	bool sound1 = false;
	int time1 = 0;
	GameOver()
	{

		gameoverImage.loadFromFile("pidor/game1.png");
		gameoverTex.loadFromImage(gameoverImage);
		gameover.setTexture(gameoverTex);
		gameover.setTextureRect(IntRect(0, 0, 1920, 1080));

	}
	void draw(RenderWindow& window, float time)
	{
		sound1 = true;
		time1 += time;
		if (time1>1500) gameoverTex.loadFromFile("pidor/gameover1.png");
		if (time1 > 3000)
		{
			gameoverTex.loadFromFile("pidor/presse.png");
			time1 = 0;
		}

		Vector2f center = window.getView().getCenter();
		Vector2f size = window.getView().getSize();
		gameover.setPosition(center.x - size.x/2, center.y - size.y/2);
		window.draw(gameover);
	}
};
class TheEnd
{
public:
	Image theendImage;
	Texture theendTex;
	Sprite theend;


	bool sound1 = false;
	int time1 = 0;
	TheEnd()
	{

		theendTex.loadFromFile("pidor/theend.png");
		theendTex.loadFromImage(theendImage);
		theend.setTexture(theendTex);
		theend.setTextureRect(IntRect(0, 0, 1920, 1080));

	}
	void draw(RenderWindow& window, float time)
	{
		time1 += time;
		if (time1 > 1500) theendTex.loadFromFile("pidor/theend.png");
		if (time1 > 3000)
		{
			theendTex.loadFromFile("pidor/presseend.png");
			time1 = 0;
		}

		Vector2f center = window.getView().getCenter();
		Vector2f size = window.getView().getSize();
		theend.setPosition(center.x - size.x / 2, center.y - size.y / 2);
		window.draw(theend);
	}
};
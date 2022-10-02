#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;


class Spravka
{
public:
	Image gameoverImage;
	Texture gameoverTex;
	Sprite gameover;

	bool sound1 = false;
	int time1 = 0;
	Spravka()
	{

		gameoverImage.loadFromFile("pidor/game1.png");
		gameoverTex.loadFromImage(gameoverImage);
		gameover.setTexture(gameoverTex);
		gameover.setTextureRect(IntRect(0, 0, 1920, 1080));

	}
}

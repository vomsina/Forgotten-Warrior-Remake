#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;

class SetVol
{
public:
	Image menuBackgroundd;
	int menuNum = 0;
	bool numsound = true;
	Texture menuBackground;
	Sprite shop;
	SetVol()
	{
		menuBackgroundd.loadFromFile("pidor/setsound1.png");
		menuBackground.loadFromImage(menuBackgroundd);
		shop.setTexture(menuBackground);
		shop.setTextureRect(IntRect(0, 0, 1920, 1080));

	}
	void draw(RenderWindow& window, Sound& monetka, Sound& damage, Sound& damage1, Sound& start, Sound& gameover, Music& music, bool& set)
	{
		if (set)
		{
			menuNum = 0;
			if (IntRect(845, 365, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }  menuBackground.loadFromFile("pidor/music13.png"); menuNum = 3; }
			else if (IntRect(1045, 365, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/music12.png"); menuNum = 2; }
			else if (IntRect(1260, 365, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/music11.png"); menuNum = 1; }
			else if (IntRect(1470, 365, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/music14.png"); menuNum = 4; }
			else if (IntRect(845, 650, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/sound13.png"); menuNum = 7; }
			else if (IntRect(1045, 650, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/sound12.png"); menuNum = 6; }
			else if (IntRect(1260, 650, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/sound11.png"); menuNum = 5; }
			else if (IntRect(1470, 650, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/sound14.png"); menuNum = 8; }
			else {
				menuBackground.loadFromFile("pidor/setsound1.png"); numsound = true;
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) { music.setVolume(30); }
				if (menuNum == 2) { music.setVolume(60); }
				if (menuNum == 3) { music.setVolume(100); }
				if (menuNum == 4) { music.setVolume(0); }
				if (menuNum == 5) { monetka.setVolume(30); damage1.setVolume(30); damage.setVolume(30); start.setVolume(30); gameover.setVolume(30); }
				if (menuNum == 6) { monetka.setVolume(60); damage1.setVolume(60); damage.setVolume(60); start.setVolume(60); gameover.setVolume(60); }
				if (menuNum == 7) { monetka.setVolume(100); damage1.setVolume(100); damage.setVolume(100); start.setVolume(100); gameover.setVolume(100); }
				if (menuNum == 8) { monetka.setVolume(0); damage1.setVolume(0); damage.setVolume(0); start.setVolume(0); gameover.setVolume(0); }
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape)) set = false;
			Vector2f center = window.getView().getCenter();
			Vector2f size = window.getView().getSize();
			shop.setPosition(center.x - size.x / 2, center.y - size.y / 2);//позиция на экране
			window.draw(shop);//сначала рисуем полоску здоровья
		}
	}
};
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;


class Pause
{
public:
	Image PauseImage;
	Texture PauseTex;
	Sprite Pause1;
	int menuNum = 0;
	bool numsound = true;
	bool buy = false;
	bool close = false;
	int time1 = 0;

	Pause()
	{
		PauseImage.loadFromFile("pidor/menu1.png");
		PauseTex.loadFromImage(PauseImage);
		Pause1.setTexture(PauseTex);
		Pause1.setTextureRect(IntRect(0, 0, 1920, 1080));

	}
	void draw(RenderWindow& window, bool& pause, float& x, float& y, float& health, int& playerScore, int& kolheal, bool& start, Sound& monetka, bool& set)
	{
		if (pause)
		{
			menuNum = 0;
			if (IntRect(53, 98, 555, 135).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }PauseTex.loadFromFile("pidor/menu11.png"); menuNum = 1; }
			else if (IntRect(475, 360, 555, 135).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }PauseTex.loadFromFile("pidor/menu12.png"); menuNum = 2; }
			else if (IntRect(967, 630, 555, 135).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); } PauseTex.loadFromFile("pidor/menu13.png"); menuNum = 3; }
			else if (IntRect(1351, 890, 555, 135).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); } PauseTex.loadFromFile("pidor/menu14.png"); menuNum = 4; }
			else {
				PauseTex.loadFromFile("pidor/menu1.png"); numsound = true;
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				fstream map1("map1.txt", ios::in);
				if (menuNum == 1) {
					start = true;
					pause = false;
				}
				if (menuNum == 2)
				{
					pause = false;
					return;
				}
				if (menuNum == 3) { set = true; pause = false; }
				if (menuNum == 4) { window.close(); }
			}
			Vector2f center = window.getView().getCenter();
			Vector2f size = window.getView().getSize();
			Pause1.setPosition(center.x - size.x / 2, center.y - size.y / 2);
			window.draw(Pause1);
		}
	}
};
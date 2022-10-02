#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;





void menu(RenderWindow& window, float& x, float& y, float& health, int& playerScore, int& kolheal, Sound& start, bool& set, Sound& monetka, bool& ismenu, int& damage, bool& help) {

	Sound monetka1 = monetka;
	start.play();
	Texture menuBackground;
	menuBackground.loadFromFile("pidor/menu.png");
	Sprite menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	fstream file("1.txt", ios::in);
	fstream map("map.txt", ios::in);
	menuBg.setPosition(0, 0);
	bool numsound = true;
	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		menuNum = 0;
		window.clear(Color(129, 181, 221));
		if (IntRect(1308, 220, 543, 120).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }  menuBackground.loadFromFile("pidor/men1.png"); menuNum = 1; }
		else if (IntRect(1308, 418, 543, 120).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/men2.png"); menuNum = 2; }
		else if (IntRect(1308, 620, 543, 120).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/men3.png"); menuNum = 3; }
		else if (IntRect(1308, 828, 543, 120).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/men4.png"); menuNum = 4; }
		else if (IntRect(1685, 30, 164, 120).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/menu5.png"); menuNum = 5; }
		else {
			menuBackground.loadFromFile("pidor/menu.png"); numsound = true;
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { ismenu = false; isMenu = false; }
			if (menuNum == 2)
			{
				for (int i = 0; i < HEIGHT_MAP; i++)
					for (int j = 0; j < WIDTH_MAP; j++)
					{
						map >> TileMap[i][j];
					}
				if (file)
				{
					file >> x; file >> y; file >> health; if (health <= 0) health = 100; file >> playerScore; file >> kolheal; file >> damage;

				}
				ismenu = false;
				isMenu = false;
			}
			if (menuNum == 3) { set = true; isMenu = false; }
			if (menuNum == 4) { window.close(); isMenu = false; }
			if (menuNum == 5) { help = true;  isMenu = false; }
		}
		window.draw(menuBg);
		window.display();

	}
}


void helpp(RenderWindow& window, bool& help) {

	Texture menuBackground;
	menuBackground.loadFromFile("pidor/help.png");
	Sprite menuBg(menuBackground);
	bool isMenu = 1;
	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) isMenu = false, help = false;
		window.draw(menuBg);
		window.display();
	}
}



void settings(RenderWindow& window, Sound& monetka, Sound& damage, Sound& damage1, Sound& start, Sound& gameover, Music& music, bool& set) {

	Texture menuBackground;
	menuBackground.loadFromFile("pidor/setsound.png");
	Sprite menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	bool numsound = true;
	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		menuNum = 0;
		if (IntRect(845, 365, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }  menuBackground.loadFromFile("pidor/music3.png"); menuNum = 3; }
		else if (IntRect(1045, 365, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/music2.png"); menuNum = 2; }
		else if (IntRect(1260, 365, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/music1.png"); menuNum = 1; }
		else if (IntRect(1470, 365, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/music4.png"); menuNum = 4; }
		else if (IntRect(845, 650, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/sound3.png"); menuNum = 7; }
		else if (IntRect(1045, 650, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/sound2.png"); menuNum = 6; }
		else if (IntRect(1260, 650, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/sound1.png"); menuNum = 5; }
		else if (IntRect(1470, 650, 118, 118).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }menuBackground.loadFromFile("pidor/sound4.png"); menuNum = 8; }
		else {
			menuBackground.loadFromFile("pidor/setsound.png"); numsound = true;
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
		if (Keyboard::isKeyPressed(Keyboard::Escape)) isMenu = false, set = false;
		window.draw(menuBg);
		window.display();
	}
}

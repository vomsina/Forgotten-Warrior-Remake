#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;


class Shop
{
public:
	Image shopImage;
	bool numsound = true;
	Texture shopTex;
	Sprite shop;
	int menuNum = 0;
	bool buy = false;
	bool close = false;
	Shop()
	{
		shopImage.loadFromFile("pidor/shop.png");
		shopTex.loadFromImage(shopImage);
		shop.setTexture(shopTex);
		shop.setTextureRect(IntRect(0, 0, 450, 443));

	}
	void draw(RenderWindow& window, int& coin, int& kolheal, int& damage, bool& isshop, Sound& monetka)
	{
		if (IntRect(772, 552, 113, 113).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }shopTex.loadFromFile("pidor/shop1.png"); menuNum = 1;}
		if (IntRect(910, 552, 113, 113).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }shopTex.loadFromFile("pidor/shop2.png"); menuNum = 2; }
		if (IntRect(1040, 552, 113, 113).contains(Mouse::getPosition(window))) { if (numsound == true) { numsound = false; monetka.play(); }shopTex.loadFromFile("pidor/shop3.png"); menuNum = 3;  }
		if (IntRect(1185, 202, 164, 51).contains(Mouse::getPosition(window)))
		{
			if (numsound == true) { numsound = false; monetka.play(); }
			buy = true;
			if (menuNum == 1) shopTex.loadFromFile("pidor/shop11.png");
			if (menuNum == 2) shopTex.loadFromFile("pidor/shop12.png");
			if (menuNum == 3) shopTex.loadFromFile("pidor/shop13.png");
		}
		else
		{
			buy = false;
			if (menuNum == 1) shopTex.loadFromFile("pidor/shop1.png");
			if (menuNum == 2) shopTex.loadFromFile("pidor/shop2.png");
			if (menuNum == 3) shopTex.loadFromFile("pidor/shop3.png");
			
		}
		
		if (IntRect(1185, 358, 164, 51).contains(Mouse::getPosition(window))) 
		{ 
			if (numsound == true) { numsound = false; monetka.play(); }
			close = true; 
			if (menuNum == 1) shopTex.loadFromFile("pidor/shop111.png");
			if (menuNum == 2) shopTex.loadFromFile("pidor/shop112.png");
			if (menuNum == 3) shopTex.loadFromFile("pidor/shop113.png");
		}
		else if(buy==false)
		{
			close = false;
			if (menuNum == 1) shopTex.loadFromFile("pidor/shop1.png");
			if (menuNum == 2) shopTex.loadFromFile("pidor/shop2.png");
			if (menuNum == 3) shopTex.loadFromFile("pidor/shop3.png");
		}
		if (menuNum == 0) { shopTex.loadFromFile("pidor/shop.png"); ; }
		if (!IntRect(772, 552, 113, 113).contains(Mouse::getPosition(window)) && !IntRect(910, 552, 113, 113).contains(Mouse::getPosition(window)) && !IntRect(1040, 552, 113, 113).contains(Mouse::getPosition(window)) && !IntRect(1185, 202, 164, 51).contains(Mouse::getPosition(window))&& !IntRect(1185, 358, 164, 51).contains(Mouse::getPosition(window)))numsound = true;


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (close) isshop = false;
			if (buy)
			{
				if (menuNum == 1 && coin >= 55)
				{
					coin -= 55; kolheal += 1; menuNum = 0;
				}
				if (menuNum == 2 && coin >= 150 && damage != 2)
				{
					coin -= 150; damage = 2; menuNum = 0;
				}
				if (menuNum == 3 && coin >= 350 && damage != 3)
				{
					coin -= 350; damage = 3; menuNum = 0;
				}
			}
		}


		Vector2f center = window.getView().getCenter();
		Vector2f size = window.getView().getSize();

		shop.setPosition(center.x - size.x / 2 + 210, center.y - size.y / 2);

		window.draw(shop);
	}
};

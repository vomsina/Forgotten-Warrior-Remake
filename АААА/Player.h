#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace std;
using namespace sf;

int healtime = 0;
int healtextime = 0;
int herojump = 0;
int jumpCounter = 0;



class Player :public Entity {
public:
	bool healsound = false;
	bool monetka = false;
	int dir = 0, drr = 0;
	float CurrentFrame = 0;
	bool OnV = false;
	int herojump = 0;
	int herodam = 0;
	int jump_time = 0;
	bool visible = true;
	int playerScore;
	int kolheal = 0;
	bool isShoot = false;
	bool isshop = false;
	bool issunduk = false;
	int damage = 1;
	int sunduk_time = 0;
	bool ispause = false;
	Player(Image& image, String Name, float X, float Y, int W, int H) :Entity(image, Name, X, Y, W, H) {
		playerScore = 0;

		if (name == "Player1") {
			sprite.setTextureRect(IntRect(0, 0, w, h));
		}
	}


	char checkTile(float Dx, float Dy)
	{
		for (int i = (Dy / 32); i < (Dy + h) / 32; i++)
			for (int j = Dx / 30; j < (Dx + w) / 30; j++)
			{

				return TileMap[i][j];


			}
	}

	int aaa(float Dx, float Dy)
	{
		for (int i = (Dy / 32); i < (Dy + h) / 32; i++)
			for (int j = Dx / 30; j < (Dx + w) / 30; j++)
			{
				return j * 30;
			}
	}


	void control(float time) {


		if ((!Keyboard::isKeyPressed || dir == 1) && drr == 0)
		{
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 2) CurrentFrame -= 2;
			sprite.setTextureRect(IntRect(42 * int(CurrentFrame) + 42, 46, -42, 46)); 
		}
		if (!Keyboard::isKeyPressed || dir == 0)
		{
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 2) CurrentFrame -= 2;
			sprite.setTextureRect(IntRect(42 * int(CurrentFrame), 46, 42, 46));
		}
		if (dir == 0 && drr == 6)
		{
			herojump += time;
			sprite.setTextureRect(IntRect(0, 190, 42, 43));
			if (!onGround && herojump > 300)
			{
				sprite.setTextureRect(IntRect(42, 190, 42, 46));
			}
		}
		if (dir == 1 && drr == 6)
		{
			herojump += time;
			sprite.setTextureRect(IntRect(0, 237, 42, 46));
			if (!onGround && herojump > 300)
			{
				sprite.setTextureRect(IntRect(42, 237, 42, 46));
			}
		}
		if (dir == 12)
		{
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3; 
			sprite.setTextureRect(IntRect(42 * int(CurrentFrame) + 42, 94, 42, 46));
		}
		if (dir == 13)
		{
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3; 
			sprite.setTextureRect(IntRect(42 * int(CurrentFrame) + 42, 47, 42, 46));
		}
		if (onGround) { drr = 0; herojump = 0; jumpCounter = 0; jump_time = 0; }
		if (!onGround && drr != 6)
		{
			if (dir == 1) sprite.setTextureRect(IntRect(42, 237, 42, 46));
			if (dir == 0) sprite.setTextureRect(IntRect(42, 237, -42, 46));
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			if (isshop)
				isshop = false;
			else { ispause = true; visible = false; }
		}
		////////////////////////////////////////////////////////////////////////
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { dir = 1; speed = 0.1; visible = true; isshop = false; }
		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) { dir = 0; speed = 0.1; visible = true; isshop = false; }
		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))) && (checkTile(x, y) == 'P')) { x = aaa(x, y) + 10; dir = 8; sprite.setTextureRect(IntRect(0, 295, 43, 46)); speed = 0; dx = 0; visible = false; isshop = true; }
		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))) && (checkTile(x, y) == 'L')) { x = aaa(x, y) + 10; dir = 8; sprite.setTextureRect(IntRect(0, 295, 43, 46)); speed = 0; dx = 0; visible = false; }
		if ((Mouse::isButtonPressed(Mouse::Left)) && (dir == 0) && onGround) { sprite.setTextureRect(IntRect(0, 143, 42, 46)); isShoot = true; visible = true; }
		if ((Mouse::isButtonPressed(Mouse::Left)) && (dir == 1) && onGround) { sprite.setTextureRect(IntRect(42, 143, 42, 46)); isShoot = true; visible = true; }
		if ((Keyboard::isKeyPressed(Keyboard::Space)) && (onGround || jumpCounter < 2))
		{
			visible = true;
			dy = -0.32; onGround = false; drr = 6;
			jump_time += time;
			if (jump_time > 650)
			{
				jump_time = 0;
				//jumpCounter = 3;
			}

		}
		if (health <= 0) sprite.setTextureRect(IntRect(42, 237, 0, 0));
		if ((Keyboard::isKeyPressed(Keyboard::Tab) && kolheal > 0))
		{


			if (healtime > 700)
			{
				healtextime += time;
				if (healtextime < 800)
				{
					healtextime = 0;
					if (dir == 0) { sprite.setTextureRect(IntRect(0, 349, 45, 46)); }
					if (dir == 1) { sprite.setTextureRect(IntRect(0, 404, 45, 46)); }

				}
				healtime = 0;
				if (health < 100) { health += 30; kolheal -= 1; }
				if (health + 30 > 100) health = 100;
				healsound = true;
			}

		}
	}
	void checkCollisionWithMap(float Dx, float Dy)
	{
		onGround = false;
		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 30; j < (x + w) / 30; j++)
			{
				if (TileMap[i][j] == 'X' || TileMap[i][j] == '0' || TileMap[i][j] == '8' || TileMap[i][j] == 'Z' || TileMap[i][j] == 'C' || TileMap[i][j] == 'H' || TileMap[i][j] == 'J' || TileMap[i][j] == '9' || TileMap[i][j] == 'Q')
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }
					if (Dx > 0) { x = j * 30 - w; }
					if (Dx < 0) { x = j * 30 + 30; }
				}
				if (j - 1 < (x + w) / 30)
				{
					if (dir == 0 && TileMap[i][j - 1] == 's')
					{
						playerScore += 3; TileMap[i][j - 1] = ' ';
						monetka = true;
					}
				}
				if (j + 1 < (x + w) / 30)
				{
					if (TileMap[i][j + 1] == 's' && dir == 1)
					{
						playerScore += 3; TileMap[i][j + 1] = ' ';
						monetka = true;
					}
				}

				if (TileMap[i][j] == 'k')
				{
					TileMap[i][j] = 'K';
					TileMap[i][j + 1] = 'A';
					sunduk_time += 1;
					int rand_sunduk = rand() % 3 + 1;
					if (rand_sunduk == 1)
					{
						kolheal += 1;
					}
					if (rand_sunduk == 2)
					{
						playerScore += 28;
					}
					if (rand_sunduk == 3)
					{
						playerScore += 56;
					}
					issunduk = true;

				}
				else if (TileMap[i][j] == '*')
				{
					TileMap[i][j] = ':';
					TileMap[i][j + 1] = '7';
					sunduk_time += 1;
					int rand_sunduk = rand() % 3 + 1;
					if (rand_sunduk == 1)
					{
						kolheal += 1;
					}
					if (rand_sunduk == 2)
					{
						playerScore += 28;
					}
					if (rand_sunduk == 3)
					{
						playerScore += 56;
					}
					issunduk = true;

				}

			}

	}


	void update(float time, int dfx, int dfy)
	{
		control(time);
		switch (dir)
		{
		case 0:dx = speed; break;
		case 1:dx = -speed; break;
		case 12: dx - 0;
		}

		x += dx * time;
		checkCollisionWithMap(dx, 0);
		y += dy * time;
		checkCollisionWithMap(0, dy);
		sprite.setPosition(x + w / 2, y + h / 2);
		if (health <= 0) { life = false; }
		if (!isMove) { speed = 0; }
		if (life) { setPlayerCoordinateForView(x, y); }
		dy = dy + 0.0015 * time;
	}
};
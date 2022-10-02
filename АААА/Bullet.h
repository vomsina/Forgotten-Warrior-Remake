#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet :public Entity {
public:
	int direction;
	bool back = false;
	int xf = 0;
	int damage;
	Bullet(Image& image, String Name, float X, float Y, int W, int H, int dir, int dam) :Entity(image, Name, X, Y, W, H) {
		x = X;
		y = Y;
		direction = dir;
		speed = 0.2;
		w = h = 16;
		life = true;
		damage = dam;
	}


	char checkTile(float Dx, float Dy)
	{
		for (int i = (Dy / 32); i < (Dy + h) / 32; i++)
			for (int j = Dx / 30; j < (Dx + w) / 30; j++)
			{
				return TileMap[i][j];
			}
	}
	void update(float time, int dfx, int dfy)
	{

		switch (direction)
		{
		case 1:

			moveTimer += time;
			if (moveTimer > damage)
			{
				dx = speed;
				moveTimer1 += time;
				sprite.setTextureRect(IntRect(0, 0, 30, 30));
			}
			else
			{
				dx = -speed;
				sprite.setTextureRect(IntRect(0, 0, 30, 30));

			}
			if (moveTimer1 > damage + 50)
			{
				speed = 0;
				sprite.setTextureRect(IntRect(0, 0, 0, 0));
				health = 0;
			}

			break;
		case 0:
			moveTimer += time;
			if (moveTimer > damage)
			{
				dx = -speed;
				moveTimer1 += time;
				sprite.setTextureRect(IntRect(0, 0, 30, 30));
			}
			else
			{
				dx = speed;
				sprite.setTextureRect(IntRect(0, 0, 30, 30));

			}
			if (moveTimer1 > damage + 50)
			{
				speed = 0;
				sprite.setTextureRect(IntRect(0, 0, 0, 0));
				health = 0;
			} break;
		}
		x += dx * time;
		y += dy * time;
		if (y <= 0) y = 1;
		int j = x;
		if (dx == dfx && y == dfy - 13) speed = 0;
		if ((Keyboard::isKeyPressed(Keyboard::K))) std::cout << x << " " << dfx << " ";
		if (health <= 0) life = false;
		sprite.setPosition(x + w / 2, y + h / 2);
	}
	bool getback()
	{
		return back;
	}
};


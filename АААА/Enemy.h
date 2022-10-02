#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"



class Enemy :public Entity {
public:
	int dir = 0; 
	float CurrentFrame = 0;
	int time_stop = 0;
	float speed = 0.1;
	Enemy(Image& image, String Name, float X, float Y, int W, int H) :Entity(image, Name, X, Y, W, H) {
		if (name == "EasyEnemy" || name == "Fire") {
			sprite.setTextureRect(IntRect(0, 0, w, h));
			dx = speed;
			health = 30;
		}
		if (name == "Chrick")
		{
			sprite.setTextureRect(IntRect(0, 0, w, h));
			dx = speed;
			health = 150;
		}
		if (name == "MedEnemy")
		{
			sprite.setTextureRect(IntRect(0, 0, w, h));
			dx = speed;
			health = 80;
		}
		if (name == "Nina")
		{
			sprite.setTextureRect(IntRect(0, 0, w, h));
			dx = 0;
			health = 200;
		}
	}
	void checkCollisionWithMap(float Dx, float Dy)
	{
		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 30; j < (x + w) / 30; j++)
			{
				if (TileMap[i][j] == 'X' || TileMap[i][j] == '0' || TileMap[i][j] == 'M' || TileMap[i][j] == '8' || TileMap[i][j] == 'Z' || TileMap[i][j] == 'C' || TileMap[i][j] == 'H' || TileMap[i][j] == 'J' || TileMap[i][j] == '9' || TileMap[i][j] == 'Q')
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }
					if (Dx > 0) { x = j * 30 - w; dx = -speed; dir = 0; }
					if (Dx < 0) { x = j * 30 + 30;  dx = speed; dir = 1; }
				}
				if (TileMap[i][j] == '{')
				{
					if (Dy > 0) { dx = 0.1; dir = 1; }
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }
					if (Dx < 0) { x = j * 30 + 30;  dx = 0.1; dir = 1; }
					if (Dx > 0) { x = j * 30 - w; dx = -0.1; dir = 0; }
				}
				if (TileMap[i][j] == '}')
				{
					if (Dy > 0) { dx = -0.1; dir = 0; }
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }
					if (Dx < 0) { x = j * 30 + 30;  dx = speed; dir = 1; }
					if (Dx > 0) { x = j * 30 - w; dx = -speed; dir = 0; }
				}
			}

	}
	void control(float time)
	{
		if (name != "Nina")
		{
			time_stop += time;
			int dir_stop = rand() % 2;
			int rand_stop = rand() % 3000 + 1000;
			int rand1_stop = rand() % 5000 + 3000;
			if (time_stop > rand_stop)
			{
				dx = 0;
				if (time_stop > rand1_stop)
				{
					time_stop = 0;
					if (dir == 1)
					{
						if (dir_stop)
						{
							dx = 0.1;
						}
						else
						{
							dx = -0.1;
							dir = 0;
						}
					}
					else
					{
						if (dir_stop)
							dx = -0.1;
						else
						{
							dx = 0.1;
							dir = 1;
						}
					}
				}
			}
		}
		if (name != "Chrick" && name != "Nina")
		{
			if ((!Keyboard::isKeyPressed || dir == 1))
			{
				CurrentFrame += 0.005 * time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				sprite.setTextureRect(IntRect(42 * int(CurrentFrame) + 42, 47, -42, 46));
			}
			if (!Keyboard::isKeyPressed || dir == 0)
			{
				CurrentFrame += 0.005 * time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				sprite.setTextureRect(IntRect(42 * int(CurrentFrame), 47, 42, 46));
			}
			if (dir == 11)
			{
				CurrentFrame += 0.005 * time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				sprite.setTextureRect(IntRect(42 * int(CurrentFrame) + 42, 47, -42, 46)); 
			}
		}
		else if (name == "Chrick")
		{
			if ((!Keyboard::isKeyPressed || dir == 1))
			{
				CurrentFrame += 0.005 * time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				sprite.setTextureRect(IntRect(40 * int(CurrentFrame) + 38, 63, -40, 63)); 
			}
			if (!Keyboard::isKeyPressed || dir == 0)
			{
				CurrentFrame += 0.005 * time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				sprite.setTextureRect(IntRect(40 * int(CurrentFrame), 63, 40, 63));
			}
			if (dir == 11)
			{
				CurrentFrame += 0.005 * time;
				if (CurrentFrame > 2) CurrentFrame -= 2;
				sprite.setTextureRect(IntRect(45 * int(CurrentFrame) + 45, 57, -45, 67)); 
			}
			if (dir == 13)
			{
				sprite.setTextureRect(IntRect(0, 193, 45, 63));
			}
			if (dir == 12)
			{
				sprite.setTextureRect(IntRect(0, 128, 45, 63));
			}
		}
		else
		{

			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 2) CurrentFrame -= 2;
			sprite.setTextureRect(IntRect(42 * int(CurrentFrame), 0, 42, 46)); 
		}
	}
	void control_fire(float time)
	{
		CurrentFrame += 0.005 * time;
		if (CurrentFrame > 2) CurrentFrame -= 2;
		sprite.setTextureRect(IntRect(30 * int(CurrentFrame), 0, 30, 24));


	}


	void update(float time, int dfx, int dfy)
	{

		if (name == "EasyEnemy" || name == "MedEnemy" || name == "Chrick" || name == "Nina") {
			control(time);
			x += dx * time;
			checkCollisionWithMap(dx, 0);
			y += dy * time;
			checkCollisionWithMap(0, dy);
			sprite.setPosition(x + w / 2, y + h / 2 + 11);
			if (health <= 0) { life = false; }
			if (!isMove) { speed = 0; }
			dy = dy + 0.0015 * time;
		}
		if (name == "Fire") {
			control_fire(time);
			x += dx * time;
			checkCollisionWithMap(dx, 0);
			y += dy * time;
			checkCollisionWithMap(0, dy);
			sprite.setPosition(x + w / 2, y + h / 2 + 11);
			if (health <= 0) { life = false; }
			dy = dy + 0.0015 * time;
		}
	}
};

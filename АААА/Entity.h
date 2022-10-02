#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Entity {
public:
	int dir;
	float dx, dy, x, y, speed, moveTimer, moveTimer1;
	int w, h;
	float health;
	bool life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	String name;
	Entity(Image& image, String Name, float X, float Y, int W, int H) {
		x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0; moveTimer1 = 0;
		speed = 0; health = 100; dx = 0; dy = 0;
		life = true; onGround = false; isMove = false;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}
	virtual void update(float time, int dfx, int dfy) = 0;
	FloatRect getRect()
	{
		return FloatRect(x, y, w, h);
	}
};

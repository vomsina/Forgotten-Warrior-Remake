#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.hpp"
#include "level.hpp"


using namespace sf;

class Entity
{
public:
	float x,y,dx,dy,w,h;
	AnimationManager anim;
	std::vector<Object> obj;
	bool life, dir;
	float timer, timer_end;
	std::string Name;
	int Health;

	Entity(AnimationManager &A,int X, int Y)
	{
		anim = A;
		x = X;
		y = Y;
		dir = 0;

		life=true;
		timer=0;
		timer_end=0;
		dx=dy=0;
	}

	virtual void update(float time) = 0;

	void draw(RenderWindow &window)
	{
		anim.draw(window,x,y+h);
	}

	FloatRect getRect()
	{
		return FloatRect(x,y,w,h);
	}

	void option(std::string NAME, float SPEED=0, int HEALTH=10, std::string FIRST_ANIM="")
	{
		Name = NAME;
		if (FIRST_ANIM!="") anim.set(FIRST_ANIM);
		w = anim.getW();
		h = anim.getH();
		dx = SPEED;
		Health = HEALTH;
	}

};


#endif ENTITY_H

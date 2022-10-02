#ifndef MOVINGPLATFORM_H
#define MOVINGPLATFORM_H

#include "Entity.hpp"

class MovingPlatform: public Entity
{
public:
	MovingPlatform(AnimationManager &a, Level &lev,int x,int y):Entity(a,x,y)
	{
		option("MovingPlatform", 0.05, 0, "move");
	}

	void update(float time)
	{
		x += dx * time;
		timer+=time;
		if (timer>6000) {dx*=-1;timer=0;}
		anim.tick(time);
	}

};

#endif MOVINGPLATFORM_H

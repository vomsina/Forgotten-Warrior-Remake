#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <SFML/Graphics.hpp>

class HealthBar
{
public:
	Texture t;
	Sprite s;
	int max;
	RectangleShape bar;

	HealthBar()
	{
		t.loadFromFile("files/images/HealthBar.png");
		s.setTexture(t);

		bar.setFillColor(Color(0,0,0));
		max = 100;
	}

	void update(int k)
	{
		if (k>0) if (k<max) bar.setSize( Vector2f(10, (max-k)*70/max) );
	}

   	void draw(RenderWindow &window)
	{
		Vector2f center = window.getView().getCenter();
		Vector2f size = window.getView().getSize();

		s.setPosition(   center.x - size.x/2 + 10, center.y - size.y/2 + 10);
	    bar.setPosition( center.x - size.x/2 + 11, center.y - size.y/2 + 13);

		window.draw(s);
		window.draw(bar);
	}

};

#endif HEALTHBAR_H

#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;

void setPlayerCoordinateForView(float x, float y) 
{
	float tempX = x; float tempY = y;
	if (y < 240) tempY = 240;
	if (x < 440) tempX = 440;
	if (x > 780) tempX = 780;
	view.setCenter(tempX, tempY);
}
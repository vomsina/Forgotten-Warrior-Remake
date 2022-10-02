#include <SFML/Graphics.hpp>
using namespace sf;

class LifeBar
{
public:
	Image image;
	Texture t;
	Sprite s;
	int max;
	RectangleShape bar;

	LifeBar()
	{
		image.loadFromFile("pidor/heal1.png");
		t.loadFromImage(image);
		s.setTexture(t);
		s.setTextureRect(IntRect(0,0,183,37));
		bar.setFillColor(Color(0, 0, 0));
		max = 100;
	}

	void update(int k)

	{
		if (k >0)
			if (k <= max)
				bar.setSize(Vector2f(-(max - k) * 45 / max, 6));
	}

	void draw(RenderWindow& window)
	{
		Vector2f center = window.getView().getCenter();
		Vector2f size = window.getView().getSize();

		s.setPosition(center.x - size.x / 2 + 20, center.y - size.y / 2 + 10);
		bar.setPosition(center.x - size.x / 2 + 140, center.y - size.y / 2 + 25);

		window.draw(s);
		window.draw(bar);
	}

};

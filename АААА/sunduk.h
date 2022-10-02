#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;


class Sunduk
{
public:
	Image sundukImage;

	Texture sundukTex;
	Sprite sunduk;
	int menuNum = 0;
	bool buy = false;
	bool close = false;
	int ff = 0;
	Sunduk()
	{
		sundukImage.loadFromFile("pidor/sunduk1.png");
		sundukTex.loadFromImage(sundukImage);
		sunduk.setTexture(sundukTex);
		sunduk.setTextureRect(IntRect(0, 0, 500, 140));

	}
	void draw(RenderWindow& window, int& coin, int& kolheal, int& damage, bool& issunduk)
	{
		if (issunduk)
		{
			int rand_sunduk = rand() % 3 + 1;
			if (rand_sunduk == 1)
			{
				sundukImage.loadFromFile("pidor/sunduk1.png");
				kolheal += 1;
			}
			if (rand_sunduk == 2)
			{
				sundukImage.loadFromFile("pidor/sunduk2.png");
				coin += 28;
			}
			if (rand_sunduk == 3)
			{
				sundukImage.loadFromFile("pidor/sunduk3.png");
				coin += 56;
			}
			Vector2f center = window.getView().getCenter();
			Vector2f size = window.getView().getSize();

			sunduk.setPosition(center.x - size.x / 2 + 210, center.y - size.y / 2);

			window.draw(sunduk);
			
		}
		
	}
};

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

bool xTwo = false;

bool StartGame()
{
	bool gameoverplay = false;
	bool set = false;
	bool help = false;
	RenderWindow window(VideoMode(1920, 1080), "Hi", sf::Style::Fullscreen);
	view.reset(FloatRect(0, 0, 854, 480));
	Image a;
	a.loadFromFile("pidor/oblaka.png");
	Texture A;
	A.loadFromImage(a);
	Sprite lox;
	lox.setTexture(A);
	bool menusound = false;
	Font font;
	font.loadFromFile("pixar-one.otf");
	bool setpause = false;
	SetVol setvol;
	fstream volume("volume.txt", ios::in);
	fstream volume1("volumesound.txt", ios::in);
	int volmus;
	volume >> volmus;
	int volsound;
	volume1 >> volsound;


	Text text("", font, 10);

	Color color(243, 233, 233);
	text.setFillColor(color);

	Text text1("", font, 10);
	text1.setFillColor(color);

	SoundBuffer shootBuffer;
	shootBuffer.loadFromFile("sound/damage1.wav");
	Sound shoot(shootBuffer);
	shoot.setVolume(volsound);
	SoundBuffer damageBuffer;
	damageBuffer.loadFromFile("sound/damage.wav");
	Sound damage(damageBuffer);
	damage.setVolume(volsound);
	SoundBuffer monetkaBuffer;
	monetkaBuffer.loadFromFile("sound/score.wav");
	Sound monetka(monetkaBuffer);
	monetka.setVolume(volsound);
	SoundBuffer gameoverBuffer;
	gameoverBuffer.loadFromFile("sound/gameover.wav");
	Sound gameover1(gameoverBuffer);
	gameover1.setVolume(volsound);
	SoundBuffer startBuffer;
	startBuffer.loadFromFile("sound/startmenu.wav");
	Sound startsound(startBuffer);
	startsound.setVolume(volsound);

	Image map_image;
	map_image.loadFromFile("pidor/map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);

	Image map1_image;
	map1_image.loadFromFile("pidor/map12.png");
	Texture map1;
	map1.loadFromImage(map1_image);

	Image map2_image;
	map2_image.loadFromFile("pidor/map13.png");
	Texture map2;
	map2.loadFromImage(map2_image);
	Sprite s_map2;
	s_map2.setTexture(map2);

	Image heroImage;
	heroImage.loadFromFile("pidor/hero00.png");
	Image easyEnemyImage;
	easyEnemyImage.loadFromFile("pidor/enemy00.png");
	Image FireImage;
	FireImage.loadFromFile("pidor/fire.png");
	Image medEnemyImage;
	medEnemyImage.loadFromFile("pidor/medenemy.png");
	Image chrickImage;
	Image NinaImage;
	NinaImage.loadFromFile("pidor/nina.png");
	chrickImage.loadFromFile("pidor/chrick00.png");
	Player p(heroImage, "Player1", 150, 3296, 40, 32);
	Music music;
	music.openFromFile("sound/music1.wav");
	music.setVolume(volmus);
	bool ismenu = true;
	int damage2 = 1;
	while (ismenu)
	{
		menu(window, p.x, p.y, p.health, p.playerScore, p.kolheal, startsound, set, monetka, ismenu, p.damage, help);
		if (set) {
			settings(window, monetka, shoot, damage, startsound, gameover1, music, set);
			fstream volume("volume.txt", ios::out);
			fstream volume1("volumesound.txt", ios::out);
			volume << music.getVolume();
			volume1 << monetka.getVolume();
		}
		if (help) {
			helpp(window, help);
		}
	}
	music.play();
	fstream filemap("map.txt", ios::in);
	Clock clock;
	Image BulletImage1;
	BulletImage1.loadFromFile("pidor/item1.png");
	Image BulletImage2;
	BulletImage2.loadFromFile("pidor/item3.png");
	Image BulletImage3;
	BulletImage3.loadFromFile("pidor/item2.png");
	Image BulletImageEnemy;
	BulletImageEnemy.loadFromFile("pidor/bim.png");
	int savedir = 0;
	std::list<Entity*> entities;
	std::list<Entity*> deadent;
	std::list<Entity*>::iterator it;
	std::list<Entity*>::iterator it2;
	float herodamage = 0;
	float CurrentFrame = 0;
	bool MedEnemyDamage = false;
	bool start = false;
	LifeBar lifeBarPlayer;
	Shop shop;
	GameOver gameover;
	Pause pause;
	Image sundukImage;
	Texture sundukTex;
	Sprite sunduk;
	TheEnd theend1;
	bool bossdie = false;
	bool theend = false;
	sundukImage.loadFromFile("pidor/sunduk1.png");
	sundukTex.loadFromImage(sundukImage);
	sunduk.setTexture(sundukTex);
	sunduk.setTextureRect(IntRect(0, 0, 500, 140));
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == 'E')
			{
				entities.push_back(new Enemy(easyEnemyImage, "EasyEnemy", j * 30 - 44, i * 32 - 45, 45, 44));
			}
			if (TileMap[i][j] == 'F')
			{
				entities.push_back(new Enemy(FireImage, "Fire", j * 30, i * 32 + 8, 30, 24));
			}
			if (TileMap[i][j] == 'W')
			{
				entities.push_back(new Enemy(medEnemyImage, "MedEnemy", j * 30 - 44, i * 32 - 45, 45, 44));
			}
			if (TileMap[i][j] == 'S')
			{
				entities.push_back(new Enemy(chrickImage, "Chrick", j * 30 - 100, i * 32 - 45, 33, 57));
			}
			if (TileMap[i][j] == '+')
			{
				entities.push_back(new Enemy(NinaImage, "Nina", j * 30 - 44, i * 32 - 45, 45, 44));
			}
		}
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float time1 = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 750;
		time1 = time1 / 700;
		Event event;
		herodamage += time;
		healtime += time;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Space)
				{
					jumpCounter++;
					xTwo = true;
				}
			if (event.type == sf::Event::Closed)
			{
				window.close(); return false;
			}
		}
		if (p.isShoot == true)
		{
			p.isShoot = false;

			if (p.dir == 0 && herodamage > 600 + p.damage * 100 + 20)
			{
				herodamage = 0;
				if (p.damage == 1)
				{
					p.isShoot = false; entities.push_back(new Bullet(BulletImage1, "Bullet1", p.x + 35, p.y + 13, 16, 16, p.dir, 300));
					shoot.play();
				}
				if (p.damage == 2)
				{
					p.isShoot = false; entities.push_back(new Bullet(BulletImage2, "Bullet2", p.x + 35, p.y + 13, 16, 16, p.dir, 400));
					shoot.play();
				}
				if (p.damage == 3)
				{
					p.isShoot = false; entities.push_back(new Bullet(BulletImage3, "Bullet3", p.x + 35, p.y + 13, 16, 16, p.dir, 500));
					shoot.play();
				}
			}
			if (p.dir == 1 && herodamage > 600 + p.damage * 100 + 20)
			{
				herodamage = 0;
				if (p.damage == 1)
				{
					p.isShoot = false; entities.push_back(new Bullet(BulletImage1, "Bullet1", p.x - 10, p.y + 13, 16, 16, p.dir, 300));
					shoot.play();
				}
				if (p.damage == 2)
				{
					p.isShoot = false; entities.push_back(new Bullet(BulletImage2, "Bullet2", p.x - 10, p.y + 13, 16, 16, p.dir, 400));
					shoot.play();
				}
				if (p.damage == 3)
				{
					p.isShoot = false; entities.push_back(new Bullet(BulletImage3, "Bullet3", p.x - 10, p.y + 13, 16, 16, p.dir, 500));
					shoot.play();
				}
			}
		}

		for (it = entities.begin(); it != entities.end();)
		{
			Entity* b = *it;
			b->update(time, p.x, p.y);
			if (b->health <= 0)
			{
				if (b->name == "Chrick") bossdie = true;
				if (b->name != "Bullet1" && b->name != "Bullet2" && b->name != "Bullet3")  p.playerScore += 3;
				it = entities.erase(it); delete b;
			}
			else it++;
		}
		for (it = entities.begin(); it != entities.end(); it++)
		{
			if ((*it)->getRect().intersects(p.getRect()) && p.visible == true)
			{
				if ((*it)->name == "Nina" && bossdie == true) theend = true;
				if ((*it)->name == "EasyEnemy")
				{
					damage.play();
					if (p.x < ((*it)->x)) (*it)->sprite.setTextureRect(IntRect(0, 311, 42, 46));
					else (*it)->sprite.setTextureRect(IntRect(0, 98, 42, 46));
					if (p.dir == 1)p.dir = 12;
					if (p.dir == 0)p.dir = 13;
					p.dx = 0;
					p.health -= 0.05;
					damage.play();

				}
				if ((*it)->name == "MedEnemy")
				{

					if (p.x < ((*it)->x)) (*it)->sprite.setTextureRect(IntRect(0, 311, 42, 46));
					else (*it)->sprite.setTextureRect(IntRect(0, 98, 42, 46));
					if (p.dir == 1)p.dir = 12;
					if (p.dir == 0)  p.dir = 13;
					p.dx = 0;
					p.health -= 0.15;
					damage.play();

				}
				if ((*it)->name == "Chrick")
				{

					if (p.x < ((*it)->x)) (*it)->sprite.setTextureRect(IntRect(0, 193, 45, 63));
					else (*it)->sprite.setTextureRect(IntRect(0, 127, 45, 63));
					if (p.dir == 1)p.dir = (12);
					if (p.dir == 0)  p.dir = (13);
					p.dx = 0;
					p.health -= 0.3;
					damage.play();

				}
				if ((*it)->name == "Fire")
				{
					if (p.dir == 1)p.dir = (12);
					if (p.dir == 0)  p.dir = (13);
					p.dx = 0, 05;
					p.health -= 0.1;
					damage.play();

				}
			}

			for (it2 = entities.begin(); it2 != entities.end(); it2++)
			{
				if ((*it)->getRect() != (*it2)->getRect())
				{
					if (((*it)->getRect().intersects((*it2)->getRect())) && ((*it)->name == "EasyEnemy" || (*it)->name == "MedEnemy" || (*it)->name == "Chrick") && ((*it2)->name == "Bullet1"))
					{
						(*it)->health -= 0.5;
						(*it)->dx = 0;
						(*it)->sprite.setTextureRect(IntRect(0, 0, 0, 0));
						if ((*it)->health < 0.2)
						{
							if ((*it)->name == "Chrick") (*it)->sprite.setTextureRect(IntRect(0, 261, 35, 57));
							else
								(*it)->sprite.setTextureRect(IntRect(0, 154, 31, 44));
						}
						damage.play();
					}
					if (((*it)->getRect().intersects((*it2)->getRect())) && (((*it)->name == "EasyEnemy") || (*it)->name == "MedEnemy" || (*it)->name == "Chrick") && ((*it2)->name == "Bullet2"))
					{
						(*it)->health -= 0.7;
						(*it)->dx = 0;
						(*it)->sprite.setTextureRect(IntRect(0, 0, 0, 0));
						if ((*it)->health < 5)
						{
							if ((*it)->name == "Chrick") (*it)->sprite.setTextureRect(IntRect(0, 261, 35, 57));
							else
								(*it)->sprite.setTextureRect(IntRect(0, 154, 31, 44));
						}
						damage.play();


					}
					if (((*it)->getRect().intersects((*it2)->getRect())) && (((*it)->name == "EasyEnemy") || (*it)->name == "MedEnemy" || (*it)->name == "Chrick") && ((*it2)->name == "Bullet3"))
					{
						(*it)->health -= 1;
						(*it)->dx = 0;
						(*it)->sprite.setTextureRect(IntRect(0, 0, 0, 0));
						if ((*it)->health < 5)
						{
							if ((*it)->name == "Chrick") (*it)->sprite.setTextureRect(IntRect(0, 261, 35, 57));
							else
								(*it)->sprite.setTextureRect(IntRect(0, 154, 31, 44));
						}
						damage.play();


					}
				}
			}

		}

		p.update(time, p.x, p.y);

		if (p.health >= 0) lifeBarPlayer.update(p.health);
		lifeBarPlayer.draw(window);
		window.setView(view);
		window.clear();
		window.draw(lox);
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (i < 35) s_map.setTexture(map2);
				if (i >= 35 && i <= 74) s_map.setTexture(map1);
				if (i > 74)s_map.setTexture(map);
				switch (TileMap[i][j])
				{
				case 'Z': s_map.setTextureRect(IntRect(0, 0, 30, 32)); break;
				case 'X': s_map.setTextureRect(IntRect(30, 0, 30, 32)); break;
				case 'C': s_map.setTextureRect(IntRect(60, 0, 30, 32)); break;
				case ' ': s_map.setTextureRect(IntRect(360, 0, 30, 32)); break;
				case '}': s_map.setTextureRect(IntRect(360, 0, 30, 32)); break;
				case 's': s_map.setTextureRect(IntRect(330, 0, 30, 32)); break;
				case '0': s_map.setTextureRect(IntRect(150, 0, 30, 32)); break;
				case 'V': s_map.setTextureRect(IntRect(150, 0, 30, 32)); break;
				case '9': s_map.setTextureRect(IntRect(180, 0, 30, 32)); break;
				case '1': s_map.setTextureRect(IntRect(180, 0, 30, 32)); break;
				case '8': s_map.setTextureRect(IntRect(120, 0, 30, 32)); break;
				case '2': s_map.setTextureRect(IntRect(120, 0, 30, 32)); break;
				case 'n': s_map.setTextureRect(IntRect(360, 0, 30, 32)); break;
				case 'N': s_map.setTextureRect(IntRect(390, 0, 30, 32)); break;
				case 'M': s_map.setTextureRect(IntRect(420, 0, 30, 32)); break;
				case 'k': s_map.setTextureRect(IntRect(450, 0, 30, 32)); break;
				case 'K': s_map.setTextureRect(IntRect(390, 0, 30, 32)); break;
				case 'J': s_map.setTextureRect(IntRect(480, 0, 30, 32)); break;
				case 'H': s_map.setTextureRect(IntRect(510, 0, 30, 32)); break;
				case 'O': s_map.setTextureRect(IntRect(210, 0, 30, 32)); break;
				case 'P': s_map.setTextureRect(IntRect(240, 0, 30, 32)); break;
				case 'I': s_map.setTextureRect(IntRect(540, 0, 30, 32)); break;
				case 'U': s_map.setTextureRect(IntRect(570, 0, 30, 32)); break;
				case 'Q': s_map.setTextureRect(IntRect(600, 0, 30, 32)); break;
				case 'A': s_map.setTextureRect(IntRect(630, 0, 30, 32)); break;
				case '*': s_map.setTextureRect(IntRect(720, 0, 30, 32)); break;
				case ':': s_map.setTextureRect(IntRect(660, 0, 30, 32)); break;
				case '7': s_map.setTextureRect(IntRect(690, 0, 30, 32)); break;
				case 'R': s_map.setTextureRect(IntRect(750, 0, 30, 32)); break;
				case 'T': s_map.setTextureRect(IntRect(780, 0, 30, 32)); break;
				case 'L': s_map.setTextureRect(IntRect(240, 0, 30, 32)); break;
				}
				s_map.setPosition(j * 30, i * 32);
				window.draw(s_map);

			}
		if (p.monetka == true || p.issunduk == true) { p.monetka = false; p.issunduk = false; monetka.play(); }
		for (it = entities.begin(); it != entities.end(); it++) {
			window.draw((*it)->sprite);
		}
		Vector2f center = window.getView().getCenter();
		Vector2f size = window.getView().getSize();
		lifeBarPlayer.draw(window);
		std::ostringstream playerKolHeal;    
		playerKolHeal << p.kolheal;		
		text.setString(playerKolHeal.str());
		text.setPosition(center.x - size.x / 2 + 42, center.y - size.y / 2 + 22);
		std::ostringstream playerScore;  
		playerScore << p.playerScore;	
		text1.setString(playerScore.str());
		if (p.playerScore < 10) text1.setPosition(center.x - size.x / 2 + 183, center.y - size.y / 2 + 21);
		if (p.playerScore >= 10) text1.setPosition(center.x - size.x / 2 + 180, center.y - size.y / 2 + 21);
		if (p.playerScore > 99) text1.setPosition(center.x - size.x / 2 + 177, center.y - size.y / 2 + 21);
		window.draw(text);
		window.draw(text1);
		window.draw(p.sprite);
		if (p.isshop) shop.draw(window, p.playerScore, p.kolheal, p.damage, p.isshop, monetka);
		pause.draw(window, p.ispause, p.x, p.y, p.health, p.playerScore, p.kolheal, start, monetka, setpause);
		if (start)
		{
			start = false;
			return true;
		}
		setvol.draw(window, monetka, shoot, damage, startsound, gameover1, music, setpause);
		
		if (p.health <= 0)
		{
			p.visible = false;
			if (gameoverplay == false)
			{
				gameoverplay = true;
				gameover1.play();
			}
			gameover.draw(window, time);
			if ((Keyboard::isKeyPressed(Keyboard::E)))
			{
				p.health = 30;
				p.life = true;
				p.visible = true;
				gameoverplay = false;
			}
		}
		if (theend) {
			theend1.draw(window, time);
			if (((Keyboard::isKeyPressed(Keyboard::E)))) return true;
		}
		if (p.healsound) { p.healsound = false; monetka.play(); }
		fstream file("1.txt", ios::out);
		fstream mapfile1("map.txt", ios::out);
		file << p.x << " " << p.y << " " << p.health << " " << p.playerScore << " " << p.kolheal << " " << p.damage << " ";
		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				mapfile1 << TileMap[i][j] << " ";
			}
		}
		window.display();
		music.setLoop(true);
		fstream volume("volume.txt", ios::out);
		fstream volume1("volumesound.txt", ios::out);
		volume << music.getVolume();
		volume1 << monetka.getVolume();

	}
}


void gameRunning() {
	if (StartGame()) { gameRunning(); }
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include "anim.h"
#include "player.h"

int main()
{
	srand((unsigned)time(NULL));

	RenderWindow window(VideoMode(512, 512), "Animation", Style::Close | Style::Resize);
	Texture playerTexture;
	playerTexture.loadFromFile("assets/tux1.png");

	Player player(&playerTexture, Vector2u(3, 9), 0.3f, 100.0f);

	float deltaTime = 0.0f;
	Clock clock;

	Font font;
	if (!font.loadFromFile("fonts/Vellyc.ttf"))
	{
		std::cout << "Couldn't load font." << std::endl;
		system("pause");
	}

	Text text, tip;
	text.setFont(font), tip.setFont(font);
	tip.setPosition(30, 80);
	text.setString("LETS PARTY!"), tip.setString("use A and D to move");
	text.setCharacterSize(80), tip.setCharacterSize(40);

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}

		player.update(deltaTime);
		size_t i = rand() % 255;
		size_t j = rand() % 255;
		size_t k = rand() % 255;
		text.setFillColor(Color(k, i, j, 255));
		tip.setFillColor(Color(j, i, k, 255));
		window.clear(Color(i, j, k, 255));
		player.draw(window);
		window.draw(text);
		window.draw(tip);
		window.display();
	}
	return 0;
}
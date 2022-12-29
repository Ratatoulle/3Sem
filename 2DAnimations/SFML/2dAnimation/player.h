#pragma once
#include <SFML/Graphics.hpp>
#include "anim.h"

using namespace sf;

class Player
{
public:
	Player(Texture* texture, Vector2u imageCount, float switchTime, float speed);
	~Player();

	void update(float deltaTime);
	void draw(RenderWindow& window);

private:
	RectangleShape body;
	Animation animation;
	unsigned row;
	float speed;
	bool faceRight;
};


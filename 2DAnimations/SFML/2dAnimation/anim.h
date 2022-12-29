#ifndef ANIM_H
#define ANIM_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Animation
{
private:
	Vector2u imageCount;
	Vector2u currentImage;
	float totalTime;
	float switchTime;
public:
	IntRect uvRect;
public:
	Animation(Texture* texture, Vector2u imageCount, float switchTime);
	~Animation();
	void update(int row, float deltaTime,bool faceRight);
};

#endif

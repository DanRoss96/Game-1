#include "Hitbox.h"



Hitbox::Hitbox()
{
}

Hitbox::Hitbox(int width, int height, int xin, int yin, bool collision)
{
	W = width;
	H = height;
	X = xin;
	Y = yin;
	Collide = collision;
}

Hitbox::~Hitbox()
{
}

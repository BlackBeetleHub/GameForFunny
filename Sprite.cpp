#include "Sprite.h"



void Sprite::init(int x, int y, int width, int height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	if (_vboID == 0) {
		glGenBuffers(1, &_vboID);

	}
	
}

void Sprite::draw()
{
}

Sprite::Sprite()
{
	_vboID = 0;
}


Sprite::~Sprite()
{
}

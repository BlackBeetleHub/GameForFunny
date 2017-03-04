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

	float vertexData[12];

	vertexData[0] = x + width;
	vertexData[1] = y + height;

	vertexData[2] = x;
	vertexData[3] = y + height;

	vertexData[4] = x;
	vertexData[5] = y;

	vertexData[6] = x;
	vertexData[7] = y;

	vertexData[8] = x + width;
	vertexData[9] = y;

	vertexData[10] = x + width;
	vertexData[11] = y + height;
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

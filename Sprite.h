#pragma once
#include<GL\glew.h>
class Sprite
{
public:
	void init(int x, int y, int width, int height);
	void draw();
	Sprite();
	~Sprite();
private:
	int _x;
	int _y;
	int _width;
	int _height;
	GLuint _vboID;
};


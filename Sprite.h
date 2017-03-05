#pragma once
#include<GL\glew.h>
class Sprite
{
public:
	void init(float x, float y, float width, float height);
	void draw();
	Sprite();
	~Sprite();
private:
	float _x;
	float _y;
	float _width;
	float _height;
	GLuint _vboID;
};


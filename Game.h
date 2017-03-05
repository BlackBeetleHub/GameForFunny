#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL\glew.h>
#include <SDL\SDL.h>
#include <string>
#include "Sprite.h"

class Game
{
public:
	Game();
	~Game();
	void Run();
	void initSystem(std::string nameWindow,int hight,int wigth);
	void GameLoop();
private:
	SDL_Window *mainwindow; /* Our window handle */
	SDL_GLContext maincontext; /* Our opengl context handle */
	void DrawGame();
	Game(const Game &g);
	Game &operator=(const Game &g);
	int _hight;
	int _wigth;
	Sprite _sprite;
};


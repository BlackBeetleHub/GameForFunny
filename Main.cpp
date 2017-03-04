#include"Game.h"
#include <iostream>

int main(int argc, char *argv[])
{
	Game game;
	game.initSystem("Develop", 1200, 600);
	game.Run();
	int a = 0;
	std::cin >> a;
	return 0;
}
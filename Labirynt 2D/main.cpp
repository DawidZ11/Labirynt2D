#include <iostream>

#include <Windows.h>
#include "Game.h"

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,int nShowCmd)
{
	Game game;

	game.Initialize(sf::Vector2i(800, 600));

	game.Run();

	std::cin.get();

	return 0;
}
#pragma once

#include <vector>

#include "Engine.h"
#include "Player.h"
#include "Wall.h"
#include "Target.h"

class Game
{
	Engine m_Engine;

	Player m_Player;
	Wall m_walls;
	Target m_target;

	bool won = false;

public:
	Game();
	~Game();

	bool Initialize(sf::Vector2i _windowSize);
	void Run();

	void win();

	void End();

};


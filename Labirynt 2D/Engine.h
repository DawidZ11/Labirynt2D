#pragma once

#include <SFML\Graphics.hpp>

//enum GAME_STATE
//{
//	GS_MENU,
//	GS_GAME,
//	GS_END
//};

class Engine
{
	sf::RenderWindow m_window;

	std::string m_windowTitle;
	sf::Vector2i m_windowSize;

	//GAME_STATE m_GameState;

public:
	Engine();
	~Engine();

	bool Initialize(std::string _windowTitle, sf::Vector2i _windowSize);


	sf::RenderWindow* GetWnd() { return &m_window; }
};


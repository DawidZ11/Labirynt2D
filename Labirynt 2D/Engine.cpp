#include "Engine.h"


bool Engine::Initialize(std::string _windowTitle, sf::Vector2i _windowSize)
{
	//m_GameState = GS_MENU;

	m_windowSize = _windowSize;
	m_windowTitle = _windowTitle;

	m_window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _windowTitle, sf::Style::Titlebar | sf::Style::Close);
	m_window.setFramerateLimit(30u);

	return true;
}

Engine::Engine()
{
}

Engine::~Engine()
{
}


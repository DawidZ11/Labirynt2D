#include "Game.h"

#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

bool Game::Initialize(sf::Vector2i _windowSize)
{
	m_Engine.Initialize("Labirynt 2D", _windowSize);

	m_walls.Init("Resources/board1.txt", sf::Vector2f(_windowSize));
	m_Player.Init();
	m_target.Init();

	return true;
}

void Game::Run()
{
	while (m_Engine.GetWnd()->isOpen())
	{
		sf::Event event;
		while (m_Engine.GetWnd()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_Engine.GetWnd()->close();
		}

		float v = 3.0f;

		if (!won)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //w
			{
				m_Player.move(0.0, -v);

				for (int i = 0; i < m_walls.GetBounds().size(); i++)
					if (m_Player.CheckCollision(m_walls.GetBounds()[i]))
						m_Player.move(0.0, v);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //s
			{
				m_Player.move(0.0, v);

				for (int i = 0; i < m_walls.GetBounds().size(); i++)
					if (m_Player.CheckCollision(m_walls.GetBounds()[i]))
						m_Player.move(0.0, -v);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //a
			{
				m_Player.move(-v, 0);

				for (int i = 0; i < m_walls.GetBounds().size(); i++)
					if (m_Player.CheckCollision(m_walls.GetBounds()[i]))
						m_Player.move(v, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // d
			{
				m_Player.move(v, 0);

				for (int i = 0; i < m_walls.GetBounds().size(); i++)
					if (m_Player.CheckCollision(m_walls.GetBounds()[i]))
						m_Player.move(-v, 0);
			}
		}
		else
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				m_Engine.GetWnd()->close();
			}
		}

		//render
		m_Engine.GetWnd()->clear();
		m_walls.Render(m_Engine.GetWnd());
		m_target.Render(m_Engine.GetWnd());
		m_Player.Render(m_Engine.GetWnd());

		if (m_Player.CheckCollision(m_target.GetBounds()))
			win();

		m_Engine.GetWnd()->display();
	}
}

void Game::win()
{
	sf::Texture tex;
	tex.loadFromFile("Resources/win.png");

	sf::RectangleShape banner;
	banner.setSize(sf::Vector2f(500.0f, 150.0f));
	banner.setTexture(&tex);
	banner.setPosition(150.0f, 225.0f);
	m_Engine.GetWnd()->draw(banner);

	won = true;
}

void Game::End()
{
}

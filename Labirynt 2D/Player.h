#pragma once

#include <SFML\Graphics.hpp>

class Player
{
	sf::CircleShape m_player;

	const float m_size = 14.0f;
	const sf::Vector2f m_pos = sf::Vector2f(15.0f, 125.0f);

public:
	Player();
	~Player();

	void Init();
	void Init(sf::Texture _texture);

	void move(float x, float y);

	void Render(sf::RenderWindow* _wnd);

	bool CheckCollision(sf::FloatRect _wallBounds);
};


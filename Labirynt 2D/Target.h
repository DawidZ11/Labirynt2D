#pragma once

#include <SFML\Graphics.hpp>

class Target
{
	sf::RectangleShape m_target;

	const float m_size = 20.0f;

public:
	Target();
	~Target();

	bool Init();

	sf::FloatRect GetBounds();

	void Render(sf::RenderWindow* _wnd);

};


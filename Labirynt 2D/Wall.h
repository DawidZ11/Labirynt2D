#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class Wall
{
	std::vector<sf::RectangleShape> m_object;
	int m_boxCount;

public:
	Wall();
	~Wall();

	bool Init(std::string _fileName, sf::Vector2f _size);

	std::vector<sf::FloatRect> GetBounds();

	void Render(sf::RenderWindow* _wnd);

};


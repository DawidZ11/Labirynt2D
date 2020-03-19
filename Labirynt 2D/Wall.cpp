#include "Wall.h"

#include <iostream>
#include <fstream>

Wall::Wall()
{
}


Wall::~Wall()
{
}

bool Wall::Init(std::string _fileName, sf::Vector2f _size)
{
	std::fstream file;

	file.open(_fileName, std::ios::in);

	if (!file.good())
	{
		std::cout << "Plik planszy nie istnieje";
		exit(0);
	}

	int boxCount = 0;


	sf::RectangleShape boxTemp;
	sf::Vector2f posTemp;
	sf::Vector2f sizeTemp;


	std::string line;
	int lineNum = 1;
	while (getline(file, line))
	{
		switch (lineNum)
		{
			case 1: posTemp.x = atof(line.c_str()) * _size.x;		break;
			case 2: posTemp.y = atof(line.c_str()) * _size.y;       break;
			case 3: sizeTemp.x = atof(line.c_str()) * _size.x;      break;
			case 4: sizeTemp.y = atof(line.c_str()) * _size.y;      break;
		}
		if (lineNum == 4) 
		{ 
			lineNum = -1; boxCount++;
			boxTemp.setOrigin(0.0f, 0.0f);
			boxTemp.setPosition(posTemp);
			boxTemp.setSize(sizeTemp);
			boxTemp.setFillColor(sf::Color::Cyan);

			m_object.push_back(boxTemp);
		}

		lineNum++;
	}

	m_boxCount = boxCount;
	
	int tes = 0;

	for(int i=0; i<m_boxCount; i++)
		std::cout << m_object[i].getPosition().x << " " << m_object[i].getPosition().y << " || " << m_object[i].getSize().x << " " << m_object[i].getSize().y << std::endl;

	file.close();

}

std::vector<sf::FloatRect> Wall::GetBounds()
{
	std::vector<sf::FloatRect> bounds;

	for (int i = 0; i < m_boxCount; i++)
	{
		bounds.push_back(m_object[i].getGlobalBounds());
	}


	return bounds;
}

void Wall::Render(sf::RenderWindow* _wnd)
{
	for (int i = 0; i < m_boxCount; i++)
	{
		_wnd->draw(m_object[i]);
	}
	
	//std::cout << std::endl << m_boxCount;
}

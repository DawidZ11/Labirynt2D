#include "Target.h"



Target::Target()
{
}


Target::~Target()
{
}

bool Target::Init()
{
	m_target.setOrigin(0.0f, 0.0f);
	m_target.setPosition(760.0f, 560.0f);
	m_target.setSize(sf::Vector2f(m_size, m_size));
	m_target.setFillColor(sf::Color::Yellow);

	return false;
}

sf::FloatRect Target::GetBounds()
{
	return m_target.getGlobalBounds();
}

void Target::Render(sf::RenderWindow * _wnd)
{
	_wnd->draw(m_target);
}

#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::Init()
{
	m_player.setPosition(m_pos);
	m_player.setRadius(m_size/2.0f);
}

void Player::Init(sf::Texture _texture)
{
	m_player.setPosition(m_pos);
	m_player.setRadius(m_size / 2.0f);
	m_player.setTexture(&_texture);
}

void Player::move(float x, float y)
{
	m_player.move(x, y);
}

bool Player::CheckCollision(sf::FloatRect _wallBounds)
{
	if (m_player.getGlobalBounds().intersects(_wallBounds))
		return true;

	return false;
}

void Player::Render(sf::RenderWindow * _wnd)
{
	_wnd->draw(m_player);
}
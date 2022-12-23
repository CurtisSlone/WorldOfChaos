#include "inc/Player.h"
#include "inc/Animation.h"

//Constructor
Player::Player(Vector2f resolution) {
    p_texture.loadFromFile("./graphics/spritesheet.png");
    p_sprite.setTexture(p_texture);
	p_sprite.setTextureRect(IntRect(0,580,65,65));
	m_position.x = resolution.x/2;
    m_position.y = resolution.y/2;
	p_sprite.setPosition(m_position.x,m_position.y);
}

//Return Sprite
Sprite Player::getSprite()
{
    return p_sprite;
}

//Move

void Player::moveLeft()
{
	m_LeftPressed = true;
}

void Player::moveRight()
{
	m_RightPressed = true;
}

void Player::moveUp()
{
	m_UpPressed = true;
}

void Player::moveDown()
{
	m_DownPressed = true;
}

void Player::stopLeft()
{
	m_LeftPressed = false;
}

void Player::stopRight()
{
	m_RightPressed = false;
}

void Player::stopUp()
{
	m_UpPressed = false;
}

void Player::stopDown()
{
	m_DownPressed = false;
}

Vector2f Player::getPosition()
{
	return m_position;
}
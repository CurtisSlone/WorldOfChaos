#include "inc/Player.h"


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

void Player::moveLeft(float dt)
{
	m_LeftPressed = true;
	p_sprite.setPosition(p_sprite.getPosition().x - 4,p_sprite.getPosition().y);
	
}

void Player::moveRight(float dt)
{
	m_RightPressed = true;
	p_sprite.setPosition(p_sprite.getPosition().x + 4,p_sprite.getPosition().y);
}

void Player::moveUp(float dt)
{
	m_UpPressed = true;
	p_sprite.setPosition(p_sprite.getPosition().x,p_sprite.getPosition().y - 4);
}

void Player::moveDown(float dt)
{
	m_DownPressed = true;
	p_sprite.setPosition(p_sprite.getPosition().x,p_sprite.getPosition().y + 4);
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
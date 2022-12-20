#include "inc/Player.h"

//Constructor
Player::Player() {
    p_texture.loadFromFile("../graphics/spritesheet.png");
    p_sprite.setTexture(p_texture);
    
}

//Spawn player
void Player::spawn(Vector2f resolution)
{
    m_Position.x = resolution.x/2;
    m_Position.y = resolution.y/2;

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
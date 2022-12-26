#include "inc/Player.h"

//Return Sprite
Sprite Player::getSprite()
{
    return p_sprite;
}

	// p_sprite.setPosition(p_sprite.getPosition().x - 4,p_sprite.getPosition().y);
	

Vector2f Player::getPosition()
{
	return m_position;
}

// Move Char
void Player::move(int dir, float dt)
{
	switch(dir)
	{
		case 8:
			p_sprite.move(0,-4);
			break;
		case 9:
			p_sprite.move(-4,0);
			break;
		case 10:
			p_sprite.move(0,4);
			break;
		case 11:
			p_sprite.move(4,0);
			break;
	}
}
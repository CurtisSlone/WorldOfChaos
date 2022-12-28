#include "inc/Player.h"
//Return Sprite
Sprite Player::getSprite()
{
    return p_sprite;
}

// Move Char
void Player::move(int dir, float dt)
{
	
	m_frame.y=(dir*65);
	m_frame.x = animate.updateFrame(m_size.y,dt);
	p_sprite.setTextureRect(IntRect(m_frame,m_size));
	switch(dir)
	{
		case 8:
			p_sprite.move(0,-4);
            playerView.move(0,-4.0f);
			break;
		case 9:
			p_sprite.move(-4,0);
            playerView.move(-4.0f,0);
        
			break;
		case 10:
			p_sprite.move(0,4);
            playerView.move(0,4.0f); 
            
			break;
		case 11:
			p_sprite.move(4,0);
            playerView.move(4.0f,0);
			break;
	}
}
#include "inc/Player.h"
// Move Char
void Player::key(Event& e)
{
	switch(e.key.code)
	{
		case Keyboard::Escape:
				g_window.close();
				break;
			case Keyboard::Up:
				m_frame.y=(Direction::UP*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				p_sprite.move(0,-4);
				break;
			case Keyboard::Down:
				m_frame.y=(Direction::DOWN*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				p_sprite.move(0,4);
				break;
			case Keyboard::Left:
				m_frame.y=(Direction::LEFT*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				p_sprite.move(-4,0);
				break;
			case Keyboard::Right:
				m_frame.y=(Direction::RIGHT*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				p_sprite.move(4,0);
				break;
	}
	
}

void Player::refresh()
{
	if(
		(p_sprite.getPosition().x >= playerView.getCenter().x + containerSize.x/2) && (p_sprite.getPosition().x < 6050) ||
		(p_sprite.getPosition().x <= playerView.getCenter().x - containerSize.x/2) && (p_sprite.getPosition().x > 198) ||
		(p_sprite.getPosition().y >= playerView.getCenter().y + containerSize.y/2) && (p_sprite.getPosition().y < 5800)||
		(p_sprite.getPosition().y <= playerView.getCenter().y - containerSize.y/2) && (p_sprite.getPosition().y > 150)
	)
	{
		playerView.move((p_sprite.getPosition() - playerView.getCenter()) * 0.0175f);
	}
	
	p_gridLoc = Vector2i((int)(playerView.getCenter().x/650),(int)(playerView.getCenter().y/650));
	g_window.setView(playerView);
	g_window.draw(p_sprite);
}	

void Player::getDelta(float dt)
{
	p_dt = dt;
}

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
				if (p_sprite.getPosition().y > 10)
					p_sprite.move(0,-4);
				if ((p_sprite.getPosition().y <= playerView.getCenter().y - containerSize.y/2) && (p_sprite.getPosition().y > 150))
					playerView.move(0,-4);
				break;
			case Keyboard::Down:
				m_frame.y=(Direction::DOWN*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				if (p_sprite.getPosition().y < 5920)
					p_sprite.move(0,4);
				if ((p_sprite.getPosition().y >= playerView.getCenter().y + containerSize.y/2) && (p_sprite.getPosition().y < 5800))
					playerView.move(0,4);
				break;
			case Keyboard::Left:
				m_frame.y=(Direction::LEFT*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				if (p_sprite.getPosition().x > 10)
					p_sprite.move(-4,0);
				if ((p_sprite.getPosition().x <= playerView.getCenter().x - containerSize.x/2) && (p_sprite.getPosition().x > 198))
					playerView.move(-4,0);
				break;
			case Keyboard::Right:
				m_frame.y=(Direction::RIGHT*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				if (p_sprite.getPosition().x < 6180)
					p_sprite.move(4,0);
				if ((p_sprite.getPosition().x >= playerView.getCenter().x + containerSize.x/2) && (p_sprite.getPosition().x < 6050))
					playerView.move(4,0);
				break;
	}
	
}

void Player::refresh()
{
	p_gridLoc = Vector2i((int)(playerView.getCenter().x/650),(int)(playerView.getCenter().y/650));
	g_window.setView(playerView);
	g_window.draw(p_sprite);
}	

void Player::getDelta(float dt)
{
	p_dt = dt;
}

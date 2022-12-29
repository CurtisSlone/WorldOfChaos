#include "inc/Player.h"
//Return Sprite
Sprite Player::getSprite()
{
    return p_sprite;
}

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
				playerView.move(0,-4.0f);
				text.move(0,-4);
				break;
			case Keyboard::Down:
				m_frame.y=(Direction::DOWN*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				p_sprite.move(0,4);
				playerView.move(0,4.0f);
				text.move(0,4);
				break;
			case Keyboard::Left:
				m_frame.y=(Direction::LEFT*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				p_sprite.move(-4,0);
				playerView.move(-4.0f,0);
				text.move(-4,0);
				break;
			case Keyboard::Right:
				m_frame.y=(Direction::RIGHT*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				p_sprite.move(4,0);
				playerView.move(4.0f,0);
				text.move(4,0);
				break;
	}
}

void Player::refresh()
{
	std::stringstream ss;
    ss << "Coords: " << playerView.getCenter().x << ", " << playerView.getCenter().y;
    text.setString(ss.str());
	g_window.setView(playerView);
	g_window.draw(p_sprite);
	g_window.draw(text);
}

void Player::getDelta(float dt)
{
	p_dt = dt;
}
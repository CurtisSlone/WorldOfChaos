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
				playerView.move(0,-4.0f);
				p_pos.move(0,-4);
				v_bounds.move(0,-4);
				break;
			case Keyboard::Down:
				m_frame.y=(Direction::DOWN*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				p_sprite.move(0,4);
				playerView.move(0,4.0f);
				p_pos.move(0,4);
				v_bounds.move(0,4);
				break;
			case Keyboard::Left:
				m_frame.y=(Direction::LEFT*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				p_sprite.move(-4,0);
				playerView.move(-4.0f,0);
				p_pos.move(-4,0);
				v_bounds.move(-4,0);
				break;
			case Keyboard::Right:
				m_frame.y=(Direction::RIGHT*65);
				m_frame.x = animate.updateFrame(m_size.y,p_dt);
				p_sprite.setTextureRect(IntRect(m_frame,m_size));
				p_sprite.move(4,0);
				playerView.move(4.0f,0);
				p_pos.move(4,0);
				v_bounds.move(4,0);
				break;
	}
}

void Player::refresh()
{
	
	g_window.setView(playerView);
	g_window.draw(p_sprite);
	//Debug Text
	//Player Position
	std::stringstream p_ss;
    p_ss << "p_pos: " << playerView.getCenter().x << ", " << playerView.getCenter().y;
    p_pos.setString(p_ss.str());
	g_window.draw(p_pos);
	//View Bounds 
	std::stringstream v_ss;
    v_ss << "v_bounds: \n Top: " << (playerView.getCenter().y-(playerView.getSize().y/2)) << "\n Left: " << (playerView.getCenter().x-(playerView.getSize().x/2)) << "\n Bottom: " << (playerView.getCenter().y+(playerView.getSize().y/2)) << "\n Right: " << (playerView.getCenter().x+(playerView.getSize().x/2));
    v_bounds.setString(v_ss.str());
	g_window.draw(v_bounds);
}

void Player::getDelta(float dt)
{
	p_dt = dt;
}
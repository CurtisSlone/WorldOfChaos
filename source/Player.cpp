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
		(p_sprite.getPosition().x >= playerView.getCenter().x + containerSize.x/2) ||
		(p_sprite.getPosition().x <= playerView.getCenter().x - containerSize.x/2) ||
		(p_sprite.getPosition().y >= playerView.getCenter().y + containerSize.y/2) ||
		(p_sprite.getPosition().y <= playerView.getCenter().y - containerSize.y/2)
	)
	{
		playerView.move((p_sprite.getPosition() - playerView.getCenter())*0.1f);
		p_pos.move((p_sprite.getPosition() - playerView.getCenter())*0.1f);
		v_bounds.move((p_sprite.getPosition() - playerView.getCenter())*0.1f);
		m_grid.move((p_sprite.getPosition() - playerView.getCenter())*0.1f);
	}
	
	p_gridLoc = Vector2i((int)(playerView.getCenter().x/650),(int)(playerView.getCenter().y/650));
	g_window.setView(playerView);
	g_window.draw(p_sprite);
	//Debug Text
	//Player Position
	std::stringstream p_ss;
    p_ss << "p_pos: " << p_sprite.getPosition().x << ", " << p_sprite.getPosition().y;
    p_pos.setString(p_ss.str());
	g_window.draw(p_pos);
	//View Bounds 
	std::stringstream v_ss;
    v_ss << "v_bounds: \n Top: " << (playerView.getCenter().y-(playerView.getSize().y/2)) << "\n Left: " << (playerView.getCenter().x-(playerView.getSize().x/2)) << "\n Bottom: " << (playerView.getCenter().y+(playerView.getSize().y/2)) << "\n Right: " << (playerView.getCenter().x+(playerView.getSize().x/2));
    v_bounds.setString(v_ss.str());
	g_window.draw(v_bounds);
	//Current Map grid
	std::stringstream g_ss;
	g_ss << "m_grid: " << p_gridLoc.x << ", " << p_gridLoc.y;
    m_grid.setString(g_ss.str());
	g_window.draw(m_grid);
}	

void Player::getDelta(float dt)
{
	p_dt = dt;
}

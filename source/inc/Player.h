#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.h"
#include "Direction.h"
#include <iostream>
#include <sstream>

using namespace sf;

class Player
{
    private:
        //Player Texture & Sprite
        Texture p_texture;
        Sprite p_sprite;
        //Player Position
        Vector2f m_position;
        // Intrect x,y,size
        Vector2i m_frame;
        Vector2i m_size;
        //Curent Animation Frame
        IntRect m_currentFrame;
        //Player Animation Sequence
        Animation animate;
        //View
        View playerView;
        float bottomBorder;
        float topBorder;
        float rightBorder;
        float leftBorder;
        //Window
        RenderWindow& g_window;
        //Delta time
        float p_dt;
        //Map Grid that player is in
        Vector2i p_gridLoc;
        //DEBUG
        //Font selection
        Font g_font;
        //Debug text
        Text p_pos{};
        Text v_bounds{};
        Text m_grid{};
        
    public:
        Player(Vector2f& resolution, RenderWindow& window) :
            m_size(Vector2i(64,64)),
            m_frame(Vector2i(0,650)),
            m_currentFrame(IntRect(m_frame,m_size)),
            animate(.01,9),
            m_position(Vector2f(810,5460)),
            playerView(FloatRect(0,4920,resolution.x,resolution.y)),
            g_window(window),
            p_gridLoc(Vector2i((int)(playerView.getCenter().x/650),(int)(playerView.getCenter().y/650)))
            {
                // ERR check font load
                if(!g_font.loadFromFile("./fonts/KOMIKAP_.ttf"))
                {
                    //ERR
                    std::cout << "Fail";
                }
                // Player Information
                p_texture.loadFromFile("./graphics/spritesheet.png");
                p_sprite.setTexture(p_texture);
	            p_sprite.setTextureRect(m_currentFrame);
	            p_sprite.setPosition(m_position);
                //Player Pos text
                p_pos.setFont(g_font);
                p_pos.setCharacterSize(50);
                p_pos.setFillColor(Color::Red);
                p_pos.setPosition(sf::Vector2f{100,5020});
                //View Bounds Text
                v_bounds.setFont(g_font);
                v_bounds.setCharacterSize(50);
                v_bounds.setFillColor(Color::Red);
                v_bounds.setPosition(sf::Vector2f{100,5220});
                //View Bounds Text
                m_grid.setFont(g_font);
                m_grid.setCharacterSize(50);
                m_grid.setFillColor(Color::Red);
                m_grid.setPosition(sf::Vector2f{100,5800});
            };
        //Handle Keyboard events
        void key(Event& e);
        // Refresh Window data
        void refresh();
        //Receieve time delta
        void getDelta(float dt);
        //Return View
        View getView(){return playerView;};
        //Return current map grid coords
        Vector2i getCurrGrid() {return p_gridLoc;};
        //Return Player Map location
        Vector2f getPos() {return m_position;};
};
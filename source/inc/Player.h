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
        // Intrect x,y,size
        Vector2i m_frame;
        Vector2i m_size;
        //Curent Animation Frame
        IntRect m_currentFrame;
        //Player Animation Sequence
        Animation animate;
        //View
        View playerView;
        FloatRect container;
        Vector2f containerSize;

        
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
            animate(.05,9),
            playerView(FloatRect(0,4920,resolution.x,resolution.y)),
            g_window(window),
            containerSize(Vector2f(playerView.getSize().x*.8,playerView.getSize().y*.8))
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
	            p_sprite.setPosition(playerView.getCenter());
                //Get Current Grid
                 p_gridLoc =Vector2i((int)(p_sprite.getPosition().x/650),(int)(p_sprite.getPosition().y/650));
                
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
};
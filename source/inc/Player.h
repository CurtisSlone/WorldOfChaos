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
        //Text
        //Font
        Font g_font;
        Text text{};
        
    public:
        Player(Vector2f& resolution, RenderWindow& window) :
            m_size(Vector2i(64,64)),
            m_frame(Vector2i(0,650)),
            m_currentFrame(IntRect(m_frame,m_size)),
            animate(.01,9),
            m_position(Vector2f(resolution.x/2,resolution.y/2)),
            playerView(FloatRect(0,0,resolution.x,resolution.y)),
            g_window(window)
            {
                if(!g_font.loadFromFile("./fonts/KOMIKAP_.ttf"))
                {
                    //ERR
                    std::cout << "Fail";
                }
                p_texture.loadFromFile("./graphics/spritesheet.png");
                p_sprite.setTexture(p_texture);
	            p_sprite.setTextureRect(m_currentFrame);
	            p_sprite.setPosition(m_position);
                text.setFont(g_font);
                text.setCharacterSize(50);
                text.setFillColor(Color::Red);
                text.setPosition(sf::Vector2f{ 100,100});
            };
        //Pass sprite to main
        Sprite getSprite();
        void key(Event& e);
        void refresh();
        void getDelta(float dt);
};
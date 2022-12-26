#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.h"

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
        
    public:
        Player(Vector2f resolution) :
            m_size(Vector2i(65,65)),
            m_frame(Vector2i(0,650)),
            m_currentFrame(IntRect(m_frame,m_size)),
            animate(9,9),
            m_position(Vector2f(resolution.x/2,resolution.y/2))
            {
                p_texture.loadFromFile("./graphics/spritesheet.png");
                p_sprite.setTexture(p_texture);
	            p_sprite.setTextureRect(m_currentFrame);
	            p_sprite.setPosition(m_position);
            };
        //Pass sprite to main
        Vector2f getPosition();
        Sprite getSprite();
        void move(int dir, float dt);

};
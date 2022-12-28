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
        //View
        View playerView;
        float bottomBorder;
        float topBorder;
        float rightBorder;
        float leftBorder;
        
    public:
        Player(Vector2f& resolution) :
            m_size(Vector2i(64,64)),
            m_frame(Vector2i(0,650)),
            m_currentFrame(IntRect(m_frame,m_size)),
            animate(.01,9),
            m_position(Vector2f(resolution.x/2,resolution.y/2)),
            playerView(FloatRect(0,0,resolution.x,resolution.y))
            {
                p_texture.loadFromFile("./graphics/spritesheet.png");
                p_sprite.setTexture(p_texture);
	            p_sprite.setTextureRect(m_currentFrame);
	            p_sprite.setPosition(m_position);
            };
        //Pass sprite to main
        Sprite getSprite();
        void move(int dir, float dt);
        Vector2f getPos(){ return m_position;};
        View getView(){return playerView;};

};
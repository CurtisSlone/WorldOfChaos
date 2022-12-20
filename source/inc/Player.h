#pragma once
#include <SFML/Graphics.hpp>
#include "Direction.h"

using namespace sf;

class Player
{
    private:
        //Player Texture & Sprite
        Texture p_texture;
        Sprite p_sprite;
        //Player Position
        Vector2f m_Position;
        //Player Dimensions
        int p_Width;
        int p_Height;
        //Walking Frames
        int p_NumWalkingFrames;
        //Is Player Moving
        bool m_Moving;
        //Player direction
        bool m_UpPressed;
        bool m_DownPressed;
        bool m_LeftPressed;
        bool m_RightPressed;


    public:
        Player();
        //Spawn
        void spawn(Vector2f resolution);
        //Pass sprite to main
        Sprite getSprite();
        // The next four functions move the player
        void moveLeft();

        void moveRight();

        void moveUp();

        void moveDown();

        // Stop the player moving in a specific direction
        void stopLeft();

        void stopRight();

        void stopUp();

        void stopDown();


};
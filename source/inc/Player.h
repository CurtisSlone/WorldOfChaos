#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Player
{
    private:
        //Player Texture & Sprite
        Texture p_texture;
        Sprite p_sprite;
        //Player Position
        Vector2f m_position;
        //Is Player Moving
        bool m_Moving;
        //Player direction
        bool m_UpPressed;
        bool m_DownPressed;
        bool m_LeftPressed;
        bool m_RightPressed;
        std::vector<IntRect> walkingRight {
            {0,715,65,65},
            {65,715,65,65},
            {130,715,65,65},
            {195,715,65,65},
            {250,715,65,65},
            {315,715,65,65},
            {380,715,65,65},
            {445,715,65,65},
            {510,715,65,65}
        };
        std::vector<IntRect> walkingLeft {
            {0,585,65,65},
            {65,585,65,65},
            {130,585,65,65},
            {195,585,65,65},
            {250,585,65,65},
            {315,585,65,65},
            {380,585,65,65},
            {445,585,65,65},
            {510,585,65,65}
        };
        std::vector<IntRect> walkingUp {
            {0,520,65,65},
            {65,520,65,65},
            {130,520,65,65},
            {195,520,65,65},
            {250,520,65,65},
            {315,520,65,65},
            {380,520,65,65},
            {445,520,65,65},
            {510,520,65,65}
        };
        std::vector<IntRect> walkingDown {
            {0,650,65,65},
            {65,650,65,65},
            {130,650,65,65},
            {195,650,65,65},
            {250,650,65,65},
            {315,650,65,65},
            {380,650,65,65},
            {445,650,65,65},
            {510,650,65,65}

        };


    public:
        Player(Vector2f resolution);
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
        //Return Position of Player
        Vector2f getPosition();

};
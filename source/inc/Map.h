#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Map 
{
    private:
        Texture bg_texture;
        Sprite bg_sprite;
        const int rows = 10;
        const int cols = 10;
        const float t_height = 650;
        const float t_width = 650;
        //Map Bounds
        const float t_bound = 0;
        const float b_bound = 6500;
        const float l_bound = 0;
        const float r_bound = 6500;
        // Game Window Reference
        RenderWindow& g_window;
        View p_view;

    public:
        Map(Player& player, RenderWindow& window) :
        g_window(window),
        p_view(player.getView())
        {
            bg_texture.loadFromFile("./graphics/images/0_0.gif");
            bg_sprite.setTexture(bg_texture);
            bg_sprite.setPosition(0,0);
        };
        void refresh() { g_window.draw(bg_sprite);};
};
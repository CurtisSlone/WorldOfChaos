#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Map 
{
    private:
        Texture bg_texture;
        Sprite bg_sprite;
        //Map Bounds
        float t_bound;
        float b_bound;
        float l_bound;
        float r_bound;
        // Game Window Reference
        RenderWindow& g_window;

    public:
        Map(Player& player, RenderWindow& window) :
        t_bound(0.f),
        b_bound(6499.f),
        l_bound(0.f),
        r_bound(6499.f),
        g_window(window)
        {
            bg_texture.loadFromFile("./graphics/images/images/Untitled-1_01.gif");
            bg_sprite.setTexture(bg_texture);
            bg_sprite.setPosition(0,0);
        };
        void refresh() { g_window.draw(bg_sprite);};
};
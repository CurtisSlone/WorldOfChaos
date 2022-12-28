#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Map 
{
    private:
        Texture bg_texture;
        Sprite bg_sprite;
        float t_bound;
        float b_bound;
        float l_bound;
        float r_bound;

    public:
        Map(Player& player) :
        t_bound(0.f),
        b_bound(6499.f),
        l_bound(0.f),
        r_bound(6499.f)
        {
            bg_texture.loadFromFile("./graphics/images/images/Untitled-1_01.gif");
            bg_sprite.setTexture(bg_texture);
            bg_sprite.setPosition(0,0);
        };
        Sprite getMap() { return bg_sprite;};
};
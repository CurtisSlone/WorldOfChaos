#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Map 
{
    private:
        Texture bg_texture;
        Sprite bg_sprite;

    public:
        Map()
        {
            bg_texture.loadFromFile("./graphics/bg.png");
            bg_sprite.setTexture(bg_texture);
            bg_sprite.setPosition(0,0);
        };
        Sprite getMap() { return bg_sprite;};
};
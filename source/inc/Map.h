#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Map 
{
    private:
    
        
        //Map Bounds
        const float t_bound = 0;
        const float b_bound = 6499;
        const float l_bound = 0;
        const float r_bound = 6499;
        // Game Window Reference
        RenderWindow& g_window;
        Player& g_player;
        Vector2i p_gridLoc;
        const View p_view;
        //Dynamic MapLoading
        std::vector<Texture> m_text;
        std::vector<Sprite> m_sprite;

    public:
        Map(Player& player, RenderWindow& window) :
        g_window(window),
        g_player(player),
        p_view(player.getView()),
        p_gridLoc(player.getCurrGrid())
        {
            int r = p_gridLoc.y - 1;
            int c = p_gridLoc.x - 1;
            Texture t;
            Sprite sp;
            std::string s;
            for(int i = 0; i<9; i++)
            {
                s = "graphics/images/" + std::to_string(c) + "_" + std::to_string(r) +".gif";
                m_text.push_back(t);
                m_text.at(i).loadFromFile(s);
                m_sprite.push_back(sp);
                m_sprite.at(i).setTexture(m_text.at(i));
                m_sprite.at(i).setPosition(Vector2f((c*650),(r*650)));
                c++;
                if(c > (p_gridLoc.x+1))
                {
                    c = p_gridLoc.x - 1;
                    r++;
                }
            }
        };
        void refresh()
    { 
        p_gridLoc = g_player.getCurrGrid();
        int r = p_gridLoc.y - 1;
        int c = p_gridLoc.x - 1;
        std::string s;
        if (p_gridLoc.x >= 1 && p_gridLoc.x <= 8 && p_gridLoc.y >=1 && p_gridLoc.y <=8)
        {
            for(Texture t : m_text)
            {
                int i = 0;
                s = "graphics/images/" + std::to_string(c) + "_" + std::to_string(r) +".gif";
                t.loadFromFile(s);
                m_sprite.at(i).setTexture(t);
                m_sprite.at(i).setPosition(Vector2f((c*650),(r*650)));
                g_window.draw(m_sprite.at(i));
                c++;
                    if(c > (p_gridLoc.x+1))
                    {
                        c = p_gridLoc.x-1;
                        r++;
                    }
                i++;
            }
        }
                
    };
};
#include <SFML/Graphics.hpp>
#include "source/inc/Player.h"
#include "source/inc/Map.h"
#include "source/inc/GameView.h"
#include <iostream>
#include <sstream>

using namespace sf;

int main()
{
    //Screen Resolution
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    // Create Window
    VideoMode vm(resolution.x, resolution.y);
    RenderWindow window(vm, "World of Chaos",Style::Fullscreen);

    //Clock
    Clock clock;
    Time dt;

    //Player
    Player player(resolution);
    //Draw Map
    Map map(player);

    //Font
    sf::Font g_font;
    if(!g_font.loadFromFile("./fonts/KOMIKAP_.ttf"))
    {
        //ERR
        std::cout << "Fail";
    }

    sf::Text text{};
    text.setFont(g_font);
    text.setCharacterSize(50);
    text.setFillColor(Color::Red);
    text.setPosition(sf::Vector2f{ 100,100});
    //Main Loop
    while(window.isOpen())
    {
        std::stringstream ss;
        ss << "Coords: " << player.getView().getCenter().x << ", " << player.getView().getCenter().y;
        text.setString(ss.str());
        //Get time delta
        Time dt = clock.restart();
        //Event
        Event event;
        // Poll event
        while (window.pollEvent(event))
        {
            //Key Switch
			switch (event.key.code)
			{
				case Keyboard::Escape:
                    window.close();
                    break;
                case Keyboard::Up:
                    player.move(8,dt.asSeconds());
                    text.move(0,-4);
                    break;
                case Keyboard::Down:
                    player.move(10,dt.asSeconds());
                    text.move(0,4);
                    break;
                case Keyboard::Left:
                    player.move(9,dt.asSeconds());
                    text.move(-4,0);
                    break;
                case Keyboard::Right:
                    player.move(11,dt.asSeconds());
                    text.move(4,0);
                    break;
			}
        }

        // Draw
        window.clear(sf::Color{ 0xAFC1D6FF });
        window.setView(player.getView());
        window.draw(map.getMap());
        window.draw(player.getSprite());
        window.draw(text);
        window.display();
    }

    return 0;
}
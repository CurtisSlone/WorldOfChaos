#include <SFML/Graphics.hpp>
#include "source/inc/Player.h"
#include "source/inc/Map.h"
#include "source/inc/GameView.h"

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

    //Create Main View
    GameView gameView(resolution);

    //Draw Map
    Map map;

    //Clock
    Clock clock;
    Time dt;

    //Player
    Player player(resolution);

    //Main Loop
    while(window.isOpen())
    {
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
                    break;
                case Keyboard::Down:
                    player.move(10,dt.asSeconds());
                    break;
                case Keyboard::Left:
                    player.move(9,dt.asSeconds());
                    break;
                case Keyboard::Right:
                    player.move(11,dt.asSeconds());
                    break;
			}
        }

        // Draw
        window.clear();
        window.setView(gameView.getView());
        window.draw(map.getMap());
        window.draw(player.getSprite());
        window.display();
    }

    return 0;
}
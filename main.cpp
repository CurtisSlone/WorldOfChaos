#include <SFML/Graphics.hpp>
#include "source/inc/Player.h"
#include "source/inc/Map.h"

using namespace sf;

int main()
{
    //Screen Resolution
    Vector2f resolution;
    resolution.x = 1920;
    resolution.y = 1080;
    // Create Window
    VideoMode vm(resolution.x, resolution.y);
    RenderWindow window(vm, "World of Chaos",Style::Fullscreen);

    //Clock
    Clock clock;
    Time dt;

    //Player
    Player player(resolution, window);

    //Draw Map
    Map map(player, window);

    
    //Main Loop
    while(window.isOpen())
    {
        //Get time delta
        Time dt = clock.restart();
        player.getDelta(dt.asSeconds());
        //Event
        Event event;
        while(window.pollEvent(event))
	    {
            player.key(event);
        }

        // Draw
        window.clear(sf::Color{ 0xAFC1D6FF });
        map.refresh();
        player.refresh();
        window.display();
    }

    return 0;
}
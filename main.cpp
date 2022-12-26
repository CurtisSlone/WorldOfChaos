#include <SFML/Graphics.hpp>
#include "source/inc/Player.h"

using namespace sf;

int main()
{
    // CREATE MAIN VIEW
    //Screen Resolution
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    // Create Window
    VideoMode vm(resolution.x, resolution.y);
    RenderWindow window(vm, "World of Chaos",Style::Fullscreen);
    //Create Main View
    View mainView(sf::FloatRect(0,0,resolution.x,resolution.y));
    float bottomBorder = (resolution.y - (resolution.y*.2));
    float topBorder = (resolution.y*.2);
    float rightBorder = (resolution.x - (resolution.x*.2));
    float leftBorder = (resolution.x*.2);
    
    //Mouse world coordinates
    Vector2f mouseWorld;
    //Mouse screen coordinates
    Vector2f mouseScreen;
    
    
    //Create a texture for background
    Texture bg;
    bg.loadFromFile("graphics/bg.png");
    Sprite bgSprite;
    bgSprite.setTexture(bg);
    bgSprite.setPosition(0,0);

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

    
        //Conditional View Move
        // Move view down
        // if(player.getPosition().y >= bottomBorder)
        // {
        //     bottomBorder+=4;
        //     topBorder+=4;
        //     mainView.move(0,4.0f);
        //     mainView.move(0,0);        
            
        // }
        // // Move view up
        // if(player.getPosition().y <= topBorder)
        // {
        //     topBorder-=4;
        //     bottomBorder-=4;
        //     mainView.move(0,-4.0f);
        //     mainView.move(0,0); 

        // }
        // // Move view right
        // if(player.getPosition().x == rightBorder)
        // {
        //     rightBorder+=4;
        //     leftBorder+=4;
        //     mainView.move(4.0f,0);
        //     mainView.move(0,0); 
        // }
        // // Move view up
        // if(player.getPosition().x == leftBorder)
        // {
        //     leftBorder-=4;
        //     rightBorder-=4;
        //     mainView.move(-4.0f,0);
        //     mainView.move(0,0); 
        // }

        // Draw
        window.clear();
        window.setView(mainView);
        window.draw(bgSprite);
        window.draw(player.getSprite());
        window.display();
    }

    return 0;
}
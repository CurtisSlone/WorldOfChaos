#include <SFML/Graphics.hpp>

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
    
    //Create object
    CircleShape shape(50.f);
    shape.setFillColor(Color::Green);
    //Set Shape position
    shape.setPosition(500,500);
    //Create a texture for background
    Texture bg;
    bg.loadFromFile("graphics/bg.png");
    Sprite bgSprite;
    bgSprite.setTexture(bg);
    bgSprite.setPosition(0,0);
    

    //Main Loop
    while(window.isOpen())
    {
        // Press Escape to Exit
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            shape.setPosition(shape.getPosition().x,shape.getPosition().y - 1);
        }
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            shape.setPosition(shape.getPosition().x,shape.getPosition().y + 1);
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            shape.setPosition(shape.getPosition().x - 1,shape.getPosition().y);
        }
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            shape.setPosition(shape.getPosition().x + 1,shape.getPosition().y);
        }

        //Conditional View Move
        // Move view down
        if(shape.getPosition().y == bottomBorder)
        {
            bottomBorder+=1;
            topBorder+=1;
            mainView.move(0,1.0f);
            mainView.move(0,0);        
            
        }
        // Move view up
        if(shape.getPosition().y == topBorder)
        {
            topBorder-=1;
            bottomBorder-=1;
            mainView.move(0,-1.0f);
            mainView.move(0,0); 

        }
        // Move view right
        if(shape.getPosition().x == rightBorder)
        {
            rightBorder+=1;
            leftBorder+=1;
            mainView.move(1.0f,0);
            mainView.move(0,0); 
        }
        // Move view up
        if(shape.getPosition().x == leftBorder)
        {
            leftBorder-=1;
            rightBorder-=1;
            mainView.move(-1.0f,0);
            mainView.move(0,0); 
        }

        ///Move view left
        if(Keyboard::isKeyPressed(Keyboard::Z))
        {
            
        }
        //Move view right
        if(Keyboard::isKeyPressed(Keyboard::X))
        {
            mainView.move(-1.f,0);
        }

        // Draw
        window.clear();
        window.setView(mainView);
        window.draw(bgSprite);
        window.draw(shape);
        window.display();
    }

    return 0;
}
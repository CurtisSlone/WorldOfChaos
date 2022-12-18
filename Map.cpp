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

    //Mouse world coordinates
    Vector2f mouseWorld;
    //Mouse screen coordinat4es
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

        // Draw
        window.clear();
        window.draw(bgSprite);
        window.draw(shape);
        window.display();
    }

    return 0;
}
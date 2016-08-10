#include <SFML/Graphics.hpp>
#include "player.h"

using namespace sf;

Vector2f generateRanPos(){

    srand(time(NULL));
    int ranX = (rand() % 750) + 1;
    int ranY = (rand() % 550) + 1;

    std::cout << ranX << " , " << ranY << std::endl;

    Vector2f vector = Vector2f(ranX, ranY);
    return vector;
}

int main()
{
    RenderWindow window(VideoMode(800, 600), "Window"); 
    Player player;
    Clock clock;
    window.setKeyRepeatEnabled(false);
    /*
    String length;
    Font testFont;
    testFont.loadFromFile("jaldiRegular.ttf");
    Text lengthText;
    lengthText.setFont(testFont);
    lengthText.setString("test");
    lengthText.setCharacterSize(24);
    lengthText.setColor(Color::Red);
    */

    CircleShape bait(30);
    bait.setRadius(10);
    bait.setFillColor(Color::Yellow);
    bait.setPosition(generateRanPos());

    RectangleShape frameBorders[4] = {RectangleShape(Vector2f(800,10)), RectangleShape(Vector2f(800,10)), 
        RectangleShape(Vector2f(10,600)), RectangleShape(Vector2f(10,600))};

    frameBorders[1].setPosition(0,590);
    frameBorders[3].setPosition(790,0);  

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type){
                case Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            } 
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (player.xDirection != 500)
                player.xDirection = -500;
            player.yDirection = 0;  
            
        }else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (player.xDirection != -500)
                player.xDirection = 500;
            player.yDirection = 0;

        }else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            player.xDirection = 0;
            if (player.yDirection != 500)
                player.yDirection = -500;

        }else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            player.xDirection = 0;
            if (player.yDirection != -500)
                player.yDirection = 500;
        }
        
        if (clock.getElapsedTime().asSeconds() >= 1.0f / 15.0f)
        {
            player.move();

            for (int d = 0; d < 4; d++)
            {
                if (player.squaresDeque.at(0).getGlobalBounds().intersects(frameBorders[d].getGlobalBounds()))
                    window.close();
            }

            if (player.squaresDeque.at(0).getGlobalBounds().intersects(bait.getGlobalBounds()))
            {
                bait.setPosition(generateRanPos());
                player.addLength();
                
            }else{

                for (int a = 0; a < player.squaresDeque.size(); a++)
                {
                    for (int b = 0; b < player.squaresDeque.size(); b++)
                    {
                        if (a != b)
                        {
                            if (player.squaresDeque.at(a).getGlobalBounds().intersects(player.squaresDeque.at(b).getGlobalBounds()))
                                window.close();
                        }
                        
                    }
                       
                }
            }
            
            clock.restart();
        }

        window.clear();
        for (int c = 0; c < 4; c++)
            window.draw(frameBorders[c]);
        for (int i = 0; i < player.squaresDeque.size(); i++)
            window.draw(player.squaresDeque.at(i));
        window.draw(bait);
       // window.draw(lengthText);
        window.display();
    }

    return 0;
}
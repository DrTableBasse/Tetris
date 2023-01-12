
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/tetromino.h"

using namespace sf;
using namespace std;

int main(void)
{
    //resolution and creation of window
    Vector2i res(700, 1080);
    RenderWindow window(VideoMode(res.x, res.y), "TetrESGI", Style::Titlebar | Style::Close);
    
    //loading icon
    auto image = sf::Image{};
    if (!image.loadFromFile("../sprites/logo.jpg"))
        cout << "Icone n'a pas chargé\n";
    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

    //texture create and loading spritesheet
    Texture texture;
    if (!texture.loadFromFile("../sprites/spritesheet.png")) {
        cout << "Le spritesheet n'a pas load\n";
    }

    Clock clock;

    //declaration of the board (default = 10x20)
    //you can access board.setsize() to change board's size
    Board board;

    //piece declaration
    Tetromino piece('j', &texture, 4);

    //Frame loop
    while (window.isOpen())
    {   
        //Event loop
        Event event;
        while (window.pollEvent(event))
        {   
            //Conditions to close the window
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                while(clock.getElapsedTime().asSeconds() > 0.05f) {
                    piece.setpos(Vector2f(-24, 0), 0); 
                    clock.restart();
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                while(clock.getElapsedTime().asSeconds() > 0.05f) {
                    piece.setpos(Vector2f(24, 0), 0); 
                    clock.restart();
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                while(clock.getElapsedTime().asSeconds() > 0.1f) {
                    piece.setpos(Vector2f(0, 0), 1); 
                    clock.restart();
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::E)) {
                while(clock.getElapsedTime().asSeconds() > 0.1f) {
                    piece.setpos(Vector2f(0, 0), -1); 
                    clock.restart();
                }
            }
        }

        //Clearing the window after each draw
        window.clear(Color(0, 0, 0));

        //draw each piece blocks (max 4)
        for (int i = 0; i != 4; i++) {
            window.draw(piece.blocks[i]);
        }
            
        //
        window.display();
    }

    return 0;
}

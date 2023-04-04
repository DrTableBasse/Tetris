/*

 Author: Yannis STEFANELLI

 Creation Date: 28-02-2023 22:12:29

 Description :
 Main project file
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../include/tetromino.h"

using namespace sf;

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
    Clock fall;

    //declaration of the board (default = 10x20)
    //you can access board.setsize() to change board's size
    Board board;

    //piece declaration
    Tetromino piece('t', &texture, 2);

    vector<Tetromino> piecesList; //push_back //emplace when previous tetromino.canControl == false

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
        //Repetitive fall
        if (fall.getElapsedTime().asSeconds() > 0.2 && piece.pos.y <= 24 * board.y) { //if piece.y < board size
            piece.setpos(Vector2f(0, 24), 0);
            fall.restart();
        } 
        if (piece.pos.y >= 24 * board.y) {
            piece.canControl = false;
        }
            
        //
        window.display();
    }

    return 0;
}

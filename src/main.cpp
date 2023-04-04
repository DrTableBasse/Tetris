/*

 Author: Yannis STEFANELLI

 Creation Date: 28-02-2023 22:12:29

 Description :
 Main project file
*/

#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/tetromino.h"
#include <SFML/Audio.hpp>
#include <list>

using namespace sf;

bool verifyColision(const std::list<Tetromino> &pieceList)
{
    auto piece = pieceList.begin();
//    for(const auto &piece : pieceList)
    for(int i = 0; i < pieceList.size(); ++i)
    {
//        if(i == pieceList.size() - 1)
//        {
//            return false;
//        }

        const Tetromino &currentPiece = *piece;
        for(const auto &block : currentPiece.blocks)
        {
            for(const auto &blockCurrentPiece : pieceList.back().blocks)
            {
                if(blockCurrentPiece.getPosition().y == block.getPosition().y + 24)
                {
                    if(blockCurrentPiece.getPosition().x == block.getPosition().x)
                    {
                        return true;
                    }
                }
            }
        }
        ++piece;
    }
    return false;
}

int main()
{
    //resolution and creation of window
    Vector2i     res(700, 1080);
    RenderWindow window(VideoMode(res.x, res.y), "TetrESGI", Style::Titlebar | Style::Close);

    //loading icon
    auto image = sf::Image{};
    if(!image.loadFromFile("../sprites/logo.jpg"))
    {
        cout << "Icone n'a pas chargé\n";
    }
    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

    //texture create and loading spritesheet
    Texture texture;
    if(!texture.loadFromFile("../sprites/spritesheet.png"))
    {
        cout << "Le spritesheet n'a pas load\n";
    }

    Clock       clock;
    Clock       fall;
    SoundBuffer buffer;
    sf::Sound   sound;

    if(!buffer.loadFromFile("../src/musique/soundtrack.ogg"))
    {
        return -1;
    }
    sound.setBuffer(buffer);
    //sound.play();

    //declaration of the board (default = 10x20)
    //you can access board.setsize() to change board's size
    Board board;

    //piece declaration
    std::list<Tetromino> pieceList;
    pieceList.emplace_back('t', &texture, 2);

    //Frame loop
    while(window.isOpen())
    {
        //Event loop
        Event event{};
        while(window.pollEvent(event))
        {
            //Conditions to close the window
            if(event.type == Event::Closed)
            {
                window.close();
            }
            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                return EXIT_SUCCESS;
            }
            //remplacer par le menu pause
            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                while(clock.getElapsedTime().asSeconds() > 0.05f)
                {
                    pieceList.back().setpos(Vector2f(-24, 0), 0);
                    clock.restart();
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                while(clock.getElapsedTime().asSeconds() > 0.05f)
                {
                    pieceList.back().setpos(Vector2f(24, 0), 0);
                    clock.restart();
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::A))
            {
                while(clock.getElapsedTime().asSeconds() > 0.1f)
                {
                    pieceList.back().setpos(Vector2f(0, 0), -1);
                    clock.restart();
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::E))
            {
                while(clock.getElapsedTime().asSeconds() > 0.1f)
                {
                    pieceList.back().setpos(Vector2f(0, 0), 1);
                    clock.restart();
                }
            }
        }

        //Clearing the window after each draw
        window.clear(Color(0, 0, 0));

        //draw each piece blocks (max 4)
        for(const auto &piece: pieceList)
        {
            for(const auto &block: piece.blocks)
            {
                window.draw(block);
            }
        }

        bool colision = verifyColision(pieceList);
        if(!colision)
        {
            //Repetitive fall
            if(fall.getElapsedTime().asSeconds() > 0.2 && pieceList.back().pos.y <= 24 * board.y)
            { //if piece.y < board size
                pieceList.back().setpos(Vector2f(0, 24), 0);
                fall.restart();
            }
            if(pieceList.back().pos.y >= 24 * board.y)
            {
                pieceList.back().canControl = false;
                pieceList.emplace_back('t', &texture, 2);
            }
        }
        else
        {
            pieceList.back().canControl = false;
            pieceList.emplace_back('t', &texture, 2);
        }
        window.display();
    }
    return 0;
}

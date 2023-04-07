/*

 Author: Yannis STEFANELLI

 Creation Date: 28-02-2023 22:12:29

 Description :
 Main project file
*/

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../include/tetromino.h"
#include <SFML/Audio.hpp>
#include <vector>

using namespace sf;

bool verifyColision(const Tetromino &piece, const std::vector<Sprite> &blockList)
{
    for(const auto &blockPiece : piece.blocks)
    {
        for(const auto &block : blockList)
        {
            if(blockPiece.getPosition().y+24 == block.getPosition().y && blockPiece.getPosition().x == block.getPosition().x)
            {
                return true;
            }
        }
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
    std::vector<Sprite> listBlock;
    Tetromino           piece(&texture, 2, Vector2i(res.x, res.y));

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
                    piece.setpos(Vector2i(-24, 0), 0);
                    clock.restart();
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                while(clock.getElapsedTime().asSeconds() > 0.05f)
                {
                    piece.setpos(Vector2i(24, 0), 0);
                    clock.restart();
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::A))
            {
                while(clock.getElapsedTime().asSeconds() > 0.1f)
                {
                    piece.setpos(Vector2i(0, 0), -1);
                    clock.restart();
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::E))
            {
                while(clock.getElapsedTime().asSeconds() > 0.1f)
                {
                    piece.setpos(Vector2i(0, 0), 1);
                    clock.restart();
                }
            }
        }

        //Clearing the window after each draw
        window.clear(Color(0, 0, 0));

        //draw each piece blocks (max 4)
        for(const auto &block: piece.blocks)
        {
            window.draw(block);
        }
        for(const auto &block: listBlock)
        {
            window.draw(block);
        }

        if(fall.getElapsedTime().asSeconds() > 0.2)
        {
            piece.setpos(Vector2i(0, 24), 0);
            if(!verifyColision(piece, listBlock))
            {
                if(piece.pos.y >= 24 * board.y)
                {
                    for(const auto &block : piece.blocks)
                    {
                        listBlock.push_back(block);
                    }
                    piece.reset();
                }
            }
            else
            {
                for(const auto &block : piece.blocks)
                {
                    listBlock.push_back(block);
                }
                piece.reset();
            }
            fall.restart();
        }
        window.display();
    }
    return 0;
}

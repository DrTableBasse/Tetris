
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/board.h"

using namespace sf;
using namespace std;

int main(void)
{
    Vector2i res(700, 1080);
    RenderWindow window(VideoMode(res.x, res.y), "TetrESGI", Style::Titlebar | Style::Close);
    auto image = sf::Image{};
    if (!image.loadFromFile("../sprites/logo.jpg"))
        cout << "Icone n'a pas chargé\n";
    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

    Board board;
    Clock clock;

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
        }

        //Clearing the window after each draw
        window.clear(Color(0, 0, 0));
        if (clock.getElapsedTime().asSeconds() > 0.4f){
            board.update();
            clock.restart();
        }
        window.draw(board.sprite);
        window.display();
    }

    return 0;
}

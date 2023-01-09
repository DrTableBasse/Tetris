
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main(void)
{
    RenderWindow window(VideoMode(960, 650), "TetrESGI", Style::Titlebar | Style::Close);
    auto image = sf::Image{};
    // if (!image.loadFromFile("../sprites/logo.jpg"))
    //     cout << "Icone n'a pas chargé\n";
    // window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

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

        window.display();
    }

    return 0;
}

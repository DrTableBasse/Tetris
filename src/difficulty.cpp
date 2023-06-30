#include <SFML/Graphics.hpp>
#include "../include/difficulty.h"
#include <iostream>


using namespace sf;



int Difficulty::increase(){
        
    if (nb_piece % 2 == 0 )  {
        speed -= 0.05; //-=5
        std::cout << "vitesse : " << std::to_string(speed) << std::endl;
        level += 1;
        txt.setString(L"level : " + to_wstring(level));
        return speed;
    }
    return -1;
};

void Difficulty::draw(RenderWindow &window) {
    window.draw(txt);
};
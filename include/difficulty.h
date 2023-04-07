#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;



class Difficulty{

    public:
        
        Clock clock;
        Text txt;
        

        Difficulty(){
            if (!font.loadFromFile("../sprites/Minecraft.ttf")){
                std::wcout << L"la police d'écriture n'a pas chargé" << std::endl;
            }
            txt.setFont(font);
            txt.setCharacterSize(24);
            txt.setFillColor(sf::Color::Red);
            txt.setString(L"level : " + to_wstring(level));
            txt.setPosition(Vector2f(500,700));
            
        };
        int increase();
        float speed = 0.5;
        int nb_piece = -1;
        int level = 1;
        int *lvlptr = &level;
        void draw(RenderWindow &window);
        


    private:
    sf::Font font;


};
/*

 Author: Yannis STEFANELLI

 Creation Date: 09-01-2023 22:22:01

 Description :

*/

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Board {
    private:
        void size(int x, int y);
    public : 
        Board(); //constructor

        char **tab;
        void setsize(int x, int y);
        void update();
        Vector2i pos;

        Texture texture;
        Sprite sprite;
    
};

void Board::size(int x, int y)
{

    tab = (char **)malloc(sizeof(char *) * 20);

    for (int i = 0; i != 20; i++)
        tab[i] = (char *)malloc(sizeof(char) * 10);
}

Board::Board(void)
{
    this->pos.x = 5;
    this->pos.y = 0;

    if (!this->texture.loadFromFile("../sprites/logo.jpg"))
        cout << "Texture n'a pas chargé\n";
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(0.1f, 0.1f);

    this->size(10, 20);
    
    
    this->tab[1][3] = '1';
    printf("%c\n", this->tab[0][3]);
    this->sprite.setPosition((600 / 10) * this->pos.x, (1080 / 20) * this->pos.y);
};

void Board::setsize(int x, int y)
{
    this->size(x, y);
};

void Board::update()
{
    pos.y += 1;
    sprite.setPosition((600 / 10) * pos.x, (1080 / 20) * pos.y);
}
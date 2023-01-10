/*

 Author: Yannis STEFANELLI

 Creation Date: 09-01-2023 22:22:01

 Description :

*/

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

//Board class definition
class Board {
    private:
        void size(int x, int y);
    public : 
        Board(); //constructor

        char **tab;
        void setsize(int x, int y);
};

//board assignment in memory
void Board::size(int x, int y)
{

    tab = (char **)malloc(sizeof(char *) * 20);

    for (int i = 0; i != 20; i++)
        tab[i] = (char *)malloc(sizeof(char) * 10);
}

//function for declaring a board
Board::Board(void)
{
    //Setting default size
    this->size(10, 20);
    
    //remove these 2 lines, they are for debug
    this->tab[1][3] = '1';
    printf("%c\n", this->tab[0][3]);
    //
};

//use this function if you want to resize your board
void Board::setsize(int x, int y)
{
    this->size(x, y);
};
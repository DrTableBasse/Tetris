/*

 Author: Yannis STEFANELLI

 Creation Date: 10-01-2023 18:21:13

 Description : function definitions to produce the board

*/

#include "../include/board.h"

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
    size(x, y);
};
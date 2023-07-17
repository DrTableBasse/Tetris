/*

 Author: Yannis STEFANELLI

 Creation Date: 10-01-2023 18:21:13

 Description : function definitions to produce the board

*/

#include "../include/board.h"

//function for declaring a board
Board::Board(int x, int y)
{
	this->x = x;
	this->y = y;
	this->tab = new int * [x];
	for(int i = 0; i < x; ++i)
	{
		this->tab[i] = new int[y];
	}
}

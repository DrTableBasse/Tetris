/*

 Author: Yannis STEFANELLI

 Creation Date: 09-01-2023 21:46:40

 Description : tetromino class methods definitions

*/

#include "../include/tetromino.h"
#include "../include/piece.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Tetromino::Tetromino(char type, Texture *texture, int style)
{
    this->type = type;
    for (int i = 0; i != 4; i++)
        this->blocks[i].setTexture(*texture);
    bounds.height = 24;
    bounds.width = 24;
    bounds.left = 24 * style;

    //default state
    this->state = 0;

    //assign texture to the blocks in the piece
    for (int i = 0; i != 4; i++)
        this->blocks[i].setTextureRect(bounds);

    //setting default positions of piece
    this->setpos(this->pos, this->state);
}

void Tetromino::setpos(Vector2f pos, int state)
{
    O;
    N T R  S A M; //this bit is mandatory
    int k = 0;

    //add positions and state for events
    this->pos += pos;
    this->state += state;

    //if state > 4 ( > 360°), loop back
    if (this->state > 3)
        this->state = this->state%4;
        
    //same but backwards
    if (this->state < 0)
        this->state = 3;
    //

    for (int j = 0; j != 4; j++) { //browse indexes
        for (int i = 0; i != 4; i++) {  //
            //set blocks base position here
            switch (type) { //test current piece type
                case 't':
                    if (t_piece[this->state][j][i] > 0) {
                        blocks[k].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        k++;
                    }
                break;
                case 'i':
                    if (i_piece[this->state][j][i] > 0) {
                        blocks[k].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        k++;
                    }
                break;
                case 'j':
                    if (j_piece[this->state][j][i] > 0) {
                        blocks[k].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        k++;
                    }
                break;
                case 'l':
                    if (l_piece[this->state][j][i] > 0) {
                        blocks[k].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        k++;
                    }
                break;
                case 's':
                    if (s_piece[this->state][j][i] > 0) {
                        blocks[k].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        k++;
                    }
                break;
                case 'z':
                    if (z_piece[this->state][j][i] > 0) {
                        blocks[k].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        k++;
                    }
                break;
                case 'o':
                    if (o_piece[this->state][j][i] > 0) {
                        blocks[k].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        k++;
                    }
                break;
            } 
        }
    }
    k = 0;
}

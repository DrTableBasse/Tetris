/*

 Author: Yannis STEFANELLI

 Creation Date: 09-01-2023 21:46:40

 Description : tetromino class methods definitions

*/

#include "../include/tetromino.h"
#include "../include/piece.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace sf;

Tetromino::Tetromino(Texture *texture, int style, Vector2i boardSize)
{
    //setting default positions of piece
    for(auto & block : this->blocks)
        block.setTexture(*texture);
    bounds.height = 24;
    bounds.width = 24;
    bounds.left = 24 * style;

    this->boardSize.x = boardSize.x;
    this->boardSize.y = boardSize.y;

    reset();

    //assign texture to the blocks in the piece
    for(auto & block : this->blocks)
        block.setTextureRect(bounds);
}

void Tetromino::setpos(Vector2i pos, int state)
{
    O;
    N T R  S A M; //this bit is mandatory
    int indexBlockPiece = 0;

    if (!canControl) { //if block locked, disable rotation & movement
        pos.x = 0;
        pos.y = 0;
        state = 0;
    }

    //add positions and state for events
    this->pos += pos;
    this->state += state;

    //if state > 4 ( > 360°), loop back
    if (this->state > 3)
        this->state = this->state%4;
        
    //same but backwards
    if (this->state < 0)
        this->state = 3;

    for (int j = 0; j != 4; j++) { //browse indexes
        for (int i = 0; i != 4; i++) {  //
            //set blocks base position here
            switch (type) { //test current piece type
                case 't':
                    if (t_piece[this->state][j][i] > 0) {
                        blocks[indexBlockPiece].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        indexBlockPiece++;
                    }
                break;
                case 'i':
                    if (i_piece[this->state][j][i] > 0) {
                        blocks[indexBlockPiece].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        indexBlockPiece++;
                    }
                break;
                case 'j':
                    if (j_piece[this->state][j][i] > 0) {
                        blocks[indexBlockPiece].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        indexBlockPiece++;
                    }
                break;
                case 'l':
                    if (l_piece[this->state][j][i] > 0) {
                        blocks[indexBlockPiece].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        indexBlockPiece++;
                    }
                break;
                case 's':
                    if (s_piece[this->state][j][i] > 0) {
                        blocks[indexBlockPiece].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        indexBlockPiece++;
                    }
                break;
                case 'z':
                    if (z_piece[this->state][j][i] > 0) {
                        blocks[indexBlockPiece].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        indexBlockPiece++;
                    }
                break;
                case 'o':
                    if (o_piece[this->state][j][i] > 0) {
                        blocks[indexBlockPiece].setPosition(i * 24 + this->pos.x, j * 24 + this->pos.y);
                        indexBlockPiece++;
                    }
                break;
            } 
        }
    }
    indexBlockPiece = 0;
}

void Tetromino::resetType()
{
    char types[7] = { 't', 'i', 'j', 'l', 's', 'z', 'o' };
    this->type = types[std::rand() % 7];
}

bool Tetromino::verifyColision(const Tetromino &piece, const std::vector<Sprite> &blockList, Board &board, char direction)
{
	if(direction == 'L')
		for(const auto &blockPiece : piece.blocks)
		{
			for(const auto &block : blockList)
			{
				if(blockPiece.getPosition().y == block.getPosition().y && blockPiece.getPosition().x-24 == block.getPosition().x)
				{
					return true;
				}
			}
		}
	if(direction == 'R')
		for(const auto &blockPiece : piece.blocks)
		{
			for(const auto &block : blockList)
			{
				if(blockPiece.getPosition().y == block.getPosition().y && blockPiece.getPosition().x+24 == block.getPosition().x)
				{
					return true;
				}
			}
		}
	if(direction == 'D')
		for(const auto &blockPiece : piece.blocks)
		{
			if(blockPiece.getPosition().y+24 == board.y*24)
			{
				return true;
			}
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

void Tetromino::reset()
{
    resetType();
    this->state = 0;
    this->pos.x = this->boardSize.x*24/2;
    this->pos.y = 2*24;
}
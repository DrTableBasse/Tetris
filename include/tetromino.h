/*

 Author: Yannis STEFANELLI

 Creation Date: 09-01-2023 21:48:43

 Description : basic class for defining a piece composed of multiple blocks

*/

#include <SFML/Graphics.hpp>
#include "./board.h"
using namespace sf;

class Tetromino {
    private :
        int size; //used to scale down/up pieces
        char type; //this is the style of the piece
        IntRect bounds; //texture bounds (24px)
        
    public :

        Tetromino(Texture *texture, int style); //constructor
        Vector2f pos;
        Sprite blocks[4]; //sprite board containing each block inside a piece
        int state; //rotation state (max 4) = 360 degrees
        void display(Board board);
        void setpos(Vector2f pos, int state);
        void reset();
        void resetType();
        bool canControl = true;
};
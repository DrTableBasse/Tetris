/*

 Author: Yannis STEFANELLI

 Creation Date: 09-01-2023 22:22:01

 Description : this is a 2D board defined by a char **str

*/

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

//Board class definition
class Board
{
	private:

	public :
		Board(int x, int y);

		int **tab;
		int x;
		int y;
};
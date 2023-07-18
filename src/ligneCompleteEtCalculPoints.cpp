#include <iostream>
#include "../include/ligneCompleteEtCalculPoints.h"

using namespace sf;
using namespace std;

using std::cout;
using std::vector;
using std::array;
using std::rotate;
using std::endl;


int LigneCompleteEtCalculPoints::incrementeScore(int score)
{
	score = score + 100; // pour chaque ligne supprimé, on ajout 100 points
	return score;
}

void LigneCompleteEtCalculPoints::decaleLigne(int a, const bool *verif, Board board, vector<Sprite>& listBlock)
{
	for(int i = 0; i < board.x; i++)
	{
		for(int j = 0; j < board.y; j++)
		{
			if(i+1 <= board.x && board.tab[i][j] == 1 && board.tab[i+1][j] == 0)
			{
				board.tab[i+1][j] = 1;
				board.tab[i][j] = 0;
			}
		}
	}
}

void LigneCompleteEtCalculPoints::supprimerLigne(int i, Board board, vector<Sprite>& listBlock)
{
	int j;

	std::vector<Sprite> newListBlock;
	for(const auto& block : listBlock) {
		if(static_cast<int>(block.getPosition().x) / 24 != i) {
			newListBlock.push_back(block);
		}
	}
	for(j = 0; j < 10; j++)
	{
		listBlock = newListBlock;
		board.tab[i][j] = 0; //On met toutes les case de la ligne à 0
	}
}

//for(auto & block : piece.blocks)
//{
//sf::Sprite tempBlock = block;
//tempBlock.setPosition(Vector2f(block.getPosition().x+24, block.getPosition().y));
//block = tempBlock;
//}


int LigneCompleteEtCalculPoints::testLignePleine(int score, Board board, vector<Sprite>& listBlock)
{
	//le score est importé par le reste du code
	int i; //i = colonne
	int j; //j = ligne
	bool verif[20] = {true}; //Représente toute les lignes du Tableau

	for(i = 0; i < 20; i++)
	{
		//colonne
		for(j = 0; j < 10; j++)
		{
			// ligne
			if(board.tab[i][j] == 0)
			{
				//Si une seul case est vide (=0) alors la ligne n'est pas complete
				!verif[i]; //Donc on assigne False à la ligne
			}
		}
	}
	j = 0;
	for(i = 0; i < 20; i++)
	{
		//Pour chaque ligne
		if(verif[i])
		{
			// Si elle est complete :
			j = j + 1; // nombre de ligne pleine ( et donc supprimé)
			supprimerLigne(i, board, listBlock); // on suprime la ligne
			score = incrementeScore(score);// on incremente le score pour chaque ligne
		}
	}

	decaleLigne(j, verif, board, listBlock); //FOnction pour faire chuter le reste des lignes restantes après suppréssion des lignes complètes
	return score;
}

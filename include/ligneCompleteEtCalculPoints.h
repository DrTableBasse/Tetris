//
// Created by dalix on 18/07/2023.
//
#pragma once
#include <SFML/Graphics.hpp>
#include "board.h"

using namespace sf;
using namespace std;

class LigneCompleteEtCalculPoints
{
	private:

	public:
		static int incrementeScore(int score);
		static void decaleLigne(int a, const bool *verif, Board board, vector<Sprite>& listBlock);
		static void supprimerLigne(int i, Board board, vector<Sprite>& listBlock);
		static int testLignePleine(int score, Board board, vector<Sprite>& listBlock);
};
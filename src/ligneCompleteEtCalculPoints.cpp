#include <iostream>
#include <vector>
#include "../include/board.h"
 
using namespace sf;
using namespace std;
using std::cout; 
using std::vector;
using std::array; 
using std::rotate;
using std::endl;


int incrementeScore(int score){
    
    score = score + 100; // pour chaque ligne supprimé, on ajout 100 points
    return score;
}

void decaleLigne(int a, bool*verif){
    
    int i=0;
    int j,k;
    int b=0;
    int Tab[a] = {false};
        
    for(j=0;j<20;j++){
        if (verif[j]==true){ //On détermine quel lignes ont été supprimés 
            Tab[i]=j; // et on les stocke leur numéros dans un tableau
            i = i + 1;
        }
    }    
            
    for (i=0;i<a;i++){ //Décalle tous le tableau de 1 case vers le bas pour les lignes > à la ligne qui est supprimé 
        if(i==a-1){ //Si on arrive en haut du tableau :
            for(j=Tab[i];j<20-a;j++){
                for(k=0;k<10;k++){
                    Board.board[j,k] = Board.board[j+1+b,k];
                }
            }
        }
        else{ //sinon :
            for(j=Tab[i];j<Tab[i+1];j++){ //Si il y a plusieurs lignes supprimé, les lignes déscende d'autant
                for(k=0;k<10;k++){
                    Board.board[j,k] = Board.board[j+1+b,k];
                }
            b = b + 1;
            }
        }
    }
    
    for (i=0;i<a;i++){
        for(j=0;j<10;j++){ // la(les) dernière(s) lignes en haut du tableau sont mise à zéro
            Board.board[19-i,j] = 0;
        }
    }  
}

void supprimerLigne(int i) {
    
    int j;
    
    for(j=0;j<10;j++){ 
        Board.board[i,j]=0; //On met toutes les case de la ligne à 0
    }
}


int testLignePleine(int score) { //le score est importé par le reste du code 
    
    int i; //i = colonne 
    int j; //j = ligne
    bool verif[20] = {true}; //Représente toute les lignes du Tableau
    
    for(i=0;i<20;i++){ //colonne
        for(j=0;j<10;j++){ // ligne
            if(Board.board[i,j]==0){ //Si une seul case est vide (=0) alors la ligne n'est pas complete 
                verif[i]==false; //Donc on assigne False à la ligne 
            }
        }
    }
    j=0;
    for(i=0;i<20;i++){ //Pour chaque ligne
        if (verif[i]==true){ // Si elle est complete :
            j = j + 1; // nombre de ligne pleine ( et donc supprimé)
            supprimerLigne(i); // on suprime la ligne 
            score = incrementeScore(score);// on incremente le score pour chaque ligne 
        }
    }
    
    decaleLigne(j,verif); //FOnction pour faire chuter le reste des lignes restantes après suppréssion des lignes complètes
    return score;
}

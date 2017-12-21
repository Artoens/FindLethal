//
// Created by artoens on 19/12/17.
//

#ifndef FINDLETHAL_BOARD
#define FINDLETHAL_BOARD
#include "card.h"

struct board
{
	int hp;
	int capacity;
	int boardSize;
	int mana;
	CARD** cards;
};
typedef struct board BOARD;

//the board file has to have a proper format:
//Herohp(int)
//Number of minions(int)
//Mana (int)
//Capacity of board
//for each card on the board:
//name of the card (string)
//mechanics(char)
//damage(int)
//cost(int)
//life(int)
//attack(int)
//
//for a visual example open one of the two boardx.txt files
BOARD* loadBoard (char *path);

#endif //FINDLETHAL_BOARD
 

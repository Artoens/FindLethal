//
// Created by artoens on 19/12/17.
//

#ifndef FINDLETHAL_BOARD
#define FINDLETHAL_BOARD

struct board
{
	int capacity;
	int size;
	CARD** cards;
};
typedef struct board BOARD;

//the board file has to have a proper format:
//Herohp(int)
//Number of minions(int)
//Mana (int)
//for each card on the board:
//name of the card (string)
//mechanics(char)
//life(int)
//cost(int)
//attack(int)
//damage(int)
//
//for a visual exemple open one of the two boardx.txt files
HAND* loadBoard (char *path);

#endif //FINDLETHAL_BOARD
 

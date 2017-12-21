//
// Created by artoens on 19/12/17.
//

#ifndef FINDLETHAL_HAND
#define FINDLETHAL_HAND
#include "card.h"


struct hand
{
	int capacity;
	int handSize;
	CARD** cards;
};
typedef struct hand HAND;

//the hand file has to have a proper format:
//hand size(int)
//for each card in the hand:
//name of the card (string)
//mechanics(char)
//damage(int)
//cost(int)
//life(int)
//attack(int)
//
//for a visual exemple open the hand.txt file
HAND* loadHand (char *path);

#endif //FINDLETHAL_HAND

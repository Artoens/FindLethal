//
// Created by artoens on 19/12/17.
//

#ifndef FINDLETHAL_HAND
#define FINDLETHAL_HAND

struct hand
{
	int capacity;
	int size;
	CARD** cards;
};
typedef struct hand HAND;

//the hand file has to have a proper format:
//hand size(int)
//for each card in the hand:
//name of the card (string)
//mechanics(char)
//life(int)
//cost(int)
//attack(int)
//damage(int)
//
//for a visual exemple open the hand.txt file
HAND* loadHand (char *path);

#endif //FINDLETHAL_HAND

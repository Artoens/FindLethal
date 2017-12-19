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

HAND* loadHand (char *path);

#endif //FINDLETHAL_HAND

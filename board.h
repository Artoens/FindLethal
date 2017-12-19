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

HAND* loadBoard (char *path);

#endif //FINDLETHAL_BOARD
 

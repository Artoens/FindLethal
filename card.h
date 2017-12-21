//
// Created by artoens on 19/12/17.
//

#ifndef FINDLETHAL_CARD
#define FINDLETHAL_CARD

#include "card.h"


struct card
{
    char *name;
    char *mechanic;
    int attack;
    int life;
    int cost;
    int	damage;
};
typedef struct card CARD;

CARD* newCard (char* name, char* mechanic, int attack, int life, int cost, int damage);

void printCard (CARD *card);


#endif //FINDLETHAL_CARD


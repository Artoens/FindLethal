//
// Created by artoens on 19/12/17.
//

#ifndef FINDLETHAL_CARD
#define FINDLETHAL_CARD


struct card
{
    char *name;
    char mechanic;
    int life;
    int cost;
    int attack;
    int	damage;
};
typedef struct card CARD;

CARD newCard (char* name,char mechanic, int life, int cost, int attack, int damage);

#endif //FINDLETHAL_CARD


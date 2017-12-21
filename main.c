 
/*
chopper les infos des textes

créer la mains et les board (qui sont que des listes de cartes)

voir si il y a un taunt en face -> ses pv

si dmg + attaque total (charge de la main et windfury, faire *2) < vie + pv rant -> false

-> teser si dégat parfait sur les taunts
	-> si pas, faire au plus proche

-> degats restant > vie -> true

###
Si on a le temps, bien print le board

How to Lethal
###

*/

#include "hand.h"
#include "board.h"
#include "cardlist.h"
#include "utils.h"

STATE* newState(char *myBoard, char *enemiBoard, char *hand)
{
	STATE* state = malloc (sizeof (STATE));
	state->hand = loadHand(*hand);
	state->enemi = loadBoard(*enemiBoard);
	state->mine = loadBoard(*myBoard);

	return state;
}

int main(int argc, char const *argv[])
{
	STATE* state = newState()
	double sizeEnemi = sizeof(state->enemi->cards)/sizeof(CARD);
	int tauntHP = 0;
	CARD** taunts = newCardlist();
	int i;
	for (i = 0; i < sizeEnemi; ++i)
	{
		CARD this = state->enemi->cards[i];
		if (this->mechanic == "t")
			tauntHP += this->life;
	}

	for(i = 0;)
	return 0;
}
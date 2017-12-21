 
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

#define BUFFER_SIZE 80
struct state
{
	HAND *hand;
	BOARD *enemi;
	BOARD *mine;
};

typedef struct state STATE;


STATE* newState(char *myBoard, char *enemiBoard, char *hand)
{
	STATE* state = malloc (sizeof (STATE));
	state->hand = loadHand(hand);
	state->enemi = loadBoard(enemiBoard);
	state->mine = loadBoard(myBoard);

	return state;
}

int main(int argc, char const *argv[])
{
	char *quit=  malloc (BUFFER_SIZE * sizeof (char));
	char *hand = malloc (BUFFER_SIZE * sizeof (char));
	char *enemiBoard = malloc (BUFFER_SIZE * sizeof (char));
	char *myBoard = malloc (BUFFER_SIZE * sizeof (char));
	printf ("* Votre main: ");
	scanf ("%s", hand);

	printf ("* Votre board: ");
	scanf ("%s", myBoard);

	printf ("* Le board enemi: ");
	scanf ("%s", enemiBoard);

	STATE* state = newState(myBoard, enemiBoard, hand);

	int sizeEnemi = state->enemi->boardSize;
	printf("%d\n", state->enemi->hp);
	printf("%d\n", sizeEnemi);
	printf("%d\n", state->enemi->capacity);
	printf("%d\n", state->enemi->mana);
	int tauntHP = 0;
	int i;
	

	for (i = 0; i < sizeEnemi; i++)
	{
		printCard(state->enemi->cards[i]);
		if (state->enemi->cards[i]->mechanic == "t")
			tauntHP += state->enemi->cards[i]->life;
	}

	printf("%d\n", tauntHP);
	scanf ("%s", quit);
	
	return 0;
}
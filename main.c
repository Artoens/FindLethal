 /*
Nous rendons ce projet dans cet état car faute de temps nous n’avons 
pas eu le temps de trouver d’où venais le bug que nous rencontrons. 

Le load deck (avec le main dans deck) fonctionne sans problème.
Le load hand (avec le main dans hand) fonctionne sans problème.

Lorsque le hand et le deck sont loader dans le state de ce main ci
 le programme plante. Nous ne savons pas à quoi c’est dû.
 
La suite du programme fonctionne théoriquement. Nous n’avons pas 
pu faire de test et de debugging de cette partie du code parceque le début ne marche pas.
 */

 /*
 *Heartstone lethal counter*
 This program is made to check our board and your hand
 as well as the board of the enemi to know if you have
 a potential lethal play
 by: Maritn Degeldt & Sam Bertrand

Note on the card mecanics: 
t = taunt (enemies must attack minion that have taunt first)
c = charge (minion can attack immidiately)
w = windfury (minion can attack twice a turn)
n = nothing

With more time and knowledge we could have made some improvements:
-A taunt counter that checks if you have perfect damage on taunt minion
-A "How to" lethal that explain which cards does what to get lethal
-We have implemented a card printed to show the boards and hands
-we have a cardlits implemented to also build upon if we want to make 
	the program take into a count decks and draws
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
	//inialize variables
	int sizeEnemi = state->enemi->boardSize;
	int sizeMe = state->mine->boardSize;
	int sizeHand = state->hand->handSize;
	printf("%d\n", sizeHand);
	printf("%d\n", sizeMe);
	printf("%d\n", sizeEnemi);	

	
	//potential damage counter
	int potDirectDamage = 0;
	int potMinionDamage =0;
	int i;
	//hand check
	for(i=0; i < sizeHand; ++i)
	{
		if(state->hand->cards[i]->mechanic == "c")
			potMinionDamage += state->hand->cards[i]->attack;
		potDirectDamage += state->hand->cards[i]->damage;
	}
	//board check
	for (i = 0; i < sizeMe; ++i)
	{
		if(state->mine->cards[i]->mechanic == "w")
			potMinionDamage += state->mine->cards[i]->attack;
		potMinionDamage += state->mine->cards[i]->attack;
	}
	
	//reduces potential minion damage for enemi taunts
	for (i = 0; i < sizeEnemi; i++)
	{
		if (state->enemi->cards[i]->mechanic == "t")
			//the perfect taunt hp would be here
			potMinionDamage -= state->enemi->cards[i]->life;
	}

	//lethal check
	int enemiHP = state->enemi->hp;
	int Lethal=0;
	if (potMinionDamage < 0)
		potMinionDamage = 0;
	if(potMinionDamage + potDirectDamage >= enemiHP)
		Lethal = 1;

	if(Lethal == 1)
		printf("You have lethal! :D\n");
	else
		printf("You don't have lethal! :(\n");

	/*
	*/
	scanf ("%s", quit);
	return 0;
}
#include "card.h"
#include <stdio.h>
#include <stdlib.h>


CARD* newCard (char* name, char* mechanic, int attack, int life, int cost, int damage)
{
	CARD* card = malloc (sizeof (CARD));
	card->name = name;
	card->mechanic = mechanic;
	card->attack = attack;
	card->life = life;
	card->cost = cost;
	card->damage = damage;
	return card;
}

void printCard (CARD *card)
{
	printf ("-----------------(%d)\n", card->cost);
	printf ("\"%s\"\n", card->name);
	printf ("       [%s]\n", card->mechanic);
	printf ("       {%d}\n", card->damage);
	printf (">%d<-------------<%d>\n", card->attack, card->life);
	printf("\n");
}
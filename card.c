
#include "card.c"


CARD newCard (char* name,char mechanic, int life, int cost, int attack, int damage)
{
	CARD *card = malloc (sizeof (CARD));
	card->name = name;
	card->mechanic = mechanic;
	card->life = life;
	card->cost = cost;
	card->attack = attack;
	card->damage = damage;
	return card;
}
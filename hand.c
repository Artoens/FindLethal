#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "hand.h" 
#include "card.h"

//inspired from  "ECAM-C3BE-2017-Mini-Projet-Example"
HAND* loadHand (char *path)
{
	HAND *hand = NULL;
	
	FILE *file = fopen (path, "r");
	if (file != NULL)
	{
		hand = malloc (sizeof (HAND));
		char buffer[BUFFER_SIZE];
		
		// Lecture du nombre de cartes
		fgets (buffer, BUFFER_SIZE, file);
		hand->capacity = 10;
		hand->size = 0;
		hand->cards = malloc (hand->capacity * sizeof (CARD*));
		
		// Lecture des cartes
		int i;
		for (i = 0; i < hand->capacity; i++)
		{
			char *name = readString (file);
			hand->cards[i] = createCard (name, readInt (file), readInt (file), readInt (file));
		}
		
		fclose (file);
	}
	
	return hand;
}
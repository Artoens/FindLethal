#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "board.h" 
#include "card.h"

#define BUFFER_SIZE 80

//inspired from  "ECAM-C3BE-2017-Mini-Projet-Example"
//martin commentaire pour toi:
//attention à CARD* et à la fonction CreateCard
//il faut que ce sois dans le bon sens
BOARD* loadBoard (char *path)
{
	BOARD *board = NULL;
	
	FILE *file = fopen (path, "r");
	if (file != NULL)
	{
		board = malloc (sizeof (BOARD));
		char buffer[BUFFER_SIZE];

		board->hp = readInt(file);
		board->boardSize = readInt(file);
		board->mana = readInt(file);
		
		// reads the board
		fgets (buffer, BUFFER_SIZE, file);
		board->capacity = atoi (buffer);
		board->cards = malloc (board->capacity * sizeof (CARD*));
		
		// creates a card for every card in the file
		int i;
		for (i = 0; i < board->capacity; i++)
		{
			char *name = readString (file);
			char *meca = readString (file);
			//WHY DO YOU READ FROM THE LAST STUPID C
			board->cards[i] = newCard (name, meca, readInt (file), readInt (file), 
				readInt (file), readInt (file));
		}
		
		fclose (file);
	}
	
	return board;
}
//Main made to test if the hand loads correctly
/*
int main(int argc, char const *argv[])
{
	char *path = malloc (BUFFER_SIZE * sizeof (char));
	char *quit = malloc (BUFFER_SIZE * sizeof (char));

	printf ("* Votre board: ");
	scanf ("%s", path);
	

	BOARD* board = loadBoard(path);

	printf("%d\n", board->hp);
	printf("%d\n", board->boardSize);
	printf("%d\n", board->capacity);
	printf("%d\n", board->mana);

	int i;
	for (i = 0; i < board->boardSize; ++i)
	{
		printCard(board->cards[i]);
	}

	board->cards[board->boardSize+1] = newCard("Leeroy", "c", 6, 2, 5, 0);
	printCard(board->cards[board->boardSize+1]);

	scanf ("%s", quit);
	
	return 0;
}
*/
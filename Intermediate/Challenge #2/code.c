/*
Solution for Intermediate Challenge #2
Author: Keydrain
Date:   03/26/15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bintree.h"

int main(void){

	struct node *root, *room1, *room2;
	int rooms[3] = {rand() % 100, rand() % 100, rand() % 100};

	insert(rooms[0], &root, "You find yourself at an old castle.");
	insert(rooms[1], &room1, "A Dragon awaits you.");
	insert(rooms[2], &room2, "A Spider awaits you.");

	printf("Welcome. Ready to play?");
	getchar();
	printf("\n");

	struct node *current = search(rooms[0], root);

	while (current != 0) {
		char printing[180];
		strcpy(printing, read(current));
		printf("%s\n", printing);
		break;
	}

	printf("\n\n");
	return(0);
}
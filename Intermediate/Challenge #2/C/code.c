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

	struct node *tree;
	int rooms[10];
	rooms[0] = 50;

	for (int i=1; i < 10; i++){
		rooms[i] = rand() % 100;
		//printf("%d\n",rooms[i]);
	}

	insert(rooms[0], &tree, "\n\tYou find yourself at an old castle with two doors. \n\tThe gate reads:\n\tTHOSE WHO ENTER, BEWARE. THOSE WHO DON'T ENTER...\n\t(Move along would ya?)");
	insert(rooms[1], &tree, "\n\tYou find a dragon sleeps in the center of the room. \n\tHe faces a door on his right and another door is located by his tail.");
	insert(rooms[2], &tree, "\n\tYou stumble into an empty and silent room with two doors at the opposite side.");
	insert(rooms[3], &tree, "\n\tA treasure chest is in the center of the room with a door on each side.");
	insert(rooms[4], &tree, "\n\tA boy with a fiddle stares at you then glances right to a door and then left to another door");

	printf("\n\tWelcome. Ready to play?");
	getchar();

	struct node *current = search(rooms[0], tree);
	int choice;

	while (current != 0) {
		//printf("--> Debugging: %p\n", current);
		char printing[180];
		strcpy(printing, read(current));
		printf("%s\n", printing);
		printf("\n\tWhat do you do?\n\t[1: Go Left\t2: Go Right\t3: Attack\t4: Quit\t] => ");
		scanf("%d", &choice);
		if (choice == 4){
			printf("\tReally?\n\t[1: Change your mind\t 2: Quit\t] => ");
			scanf("%d", &choice);
			printf("\n");
			if (choice == 2){
				printf("\tFine. \n\tYou killed yourself. \t\nHappy?\n\n");
				return(0);
			}
		} else if (choice == 1){
			current = current->left;
		} else if (choice == 2){
			current = current->right;
		} else if (choice == 3){
			printf("\tDude. Didn't you get the memo? \n\tThis is like pre-alpha or something. \n\tQuit pressing buttons that neither of us know what they do.\n\n");
		} else {
			printf("\t*Developer facepalms*\n\t Ok. \n\tLets try reading the menu next time. \n\tThe one that's just to the left. \n\tAlrighty everyone, lets try this again!\n");
		}
	}

	printf("\n\tYou stayed sane and found an exit. \n\tYou may now return to you drab life at your cubicle.\n\tDon't look now, I think your boss is coming up behind you!\n\tOr is that your wife? Regardless, I was never here.");

	//printf("--> Debugging: %p\n", current);

	printf("\n\n");
	return(0);
}
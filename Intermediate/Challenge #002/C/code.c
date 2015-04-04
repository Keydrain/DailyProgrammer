/*
Solution for Intermediate Challenge #2
Author: Keydrain
Date:   03/28/15

Note: This was painful. This is a problem for an OO language. Or at least not a binary tree
Regardless, it was a lot of fun. It should be modifiable enough to add more rooms etc. 

Note: Program checks out fine on OSX with clang compiler. Not sure about compilation on other systems. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bintree.h"

char player[64];

// General death text.
int doomed(void){
	printf("\n\tWhelp.\n\t%s, you sure do look dead.\n\tBummer...\n\tWanna try again?\n\n\n", player);
	return(0);
}

// Type that the pointers in bintree.h point to. More variables can be added as needed.
struct cell{
	char name[32];
	char description[300];
	 int lethal;
	char death[300];
	char safe[300];
};

int main(void){

	// Setup of variables and random numbers for bintree insertion.
	struct node *tree;
	int rooms[10];
	srand((unsigned)time(NULL));
	rooms[0] = 50;

	for (int i=1; i < 10; i++){
		rooms[i] = rand() % 100;
	}

	struct cell *room1;
	struct cell *room2;
	struct cell *room3;
	struct cell *room4;
	struct cell *room5;

	// Create the rooms. This section can be changed or appended by other devs as needed. 
	// The rules follow:	Each room needs a name. I don't know why. I was going to use it at some point.
	//						Each room needs a description. This is the basic text that appears upon entering the room.
	//						Each room needs a variable lethal. Key: 0: Not lethal, 1: Lethal, 2: Not lethal, but has important text that needs to be read.
	//						Each room can have a death description, for cases where the room is still deadly
	//						Each room can have a safe description, for cases where the room is clear and action is used, or if specific text needs to be used.
	//						Any other variables that are assigned above should also be set here. 

	room1 = malloc(sizeof(struct cell));
	strcpy(room1->name, "room1");
	strcpy(room1->description, "\n\tYou find yourself at an old castle with two doors.\n\tThe gate reads:\n\tTHOSE WHO ENTER, BEWARE. THOSE WHO DON'T ENTER...\n\t(Move along would ya?)\0");
	room1->lethal = 0;
	strcpy(room1->death, "\n\t");
	strcpy(room1->safe, "\n\tLets not get carried away here, it's just the beginning of the quest.\0");

	room2 = malloc(sizeof(struct cell));
	strcpy(room2->name, "room2");
	strcpy(room2->description, "\n\tYou find a dragon sleeping in the center of the room.\n\tHe faces a door on his right and another door is located by his tail.\0");
	room2->lethal = 1;
	strcpy(room2->death, "\n\tThe dragon wakes up and discovers his next meal has appeared.\0");
	strcpy(room2->safe, "\n\tYou slew the dragon.\n\tWoot.");

	room3 = malloc(sizeof(struct cell));
	strcpy(room3->name, "room3");
	strcpy(room3->description, "\n\tYou stumble into an empty and silent room with two doors at the opposite side.\0");
	room3->lethal = 2;
	strcpy(room3->death, "\n\t");
	strcpy(room3->safe, "\n\tYou frantically swing your sword at the air. Nothing happens.\0");

	room4 = malloc(sizeof(struct cell));
	strcpy(room4->name, "room4");
	strcpy(room4->description, "\n\tA treasure chest is in the center of the room with a door on each side.\n\tWe'll grab it on our way to the next door.\n\tCome on. Let's get a move on!\0");
	room4->lethal = 1;
	strcpy(room4->death, "\n\tYou opened the chest and discovered a mimic.\n\tRegrettably, it was too late.\n\tYou were already eaten.\0");
	strcpy(room4->safe, "\n\tYou ignore the chest for some unknown reason...\0");

	room5 = malloc(sizeof(struct cell));
	strcpy(room5->name, "room5");
	strcpy(room5->description, "\n\tA boy with a fiddle stares at you then glances to the door on his right.");
	room5->lethal = 2;
	strcpy(room5->death, "\n\tYou would leave a defenseless boy in the middle of some castle in who knows where?!?\n\tYou thought he was a monster?\n\tYour the real monster here.\n\tGo back and get him.\0");
	strcpy(room5->safe, "\n\tYou take the boy's hand and look towards the doors.\n\tThe boy looks nervous.\n\tWhat could it mean?\n\tShould you have taken the boy?\n\tIs he safe with you?\n\tIn reality, none of these questions cross your mind.\0");
	
	// Inserts the rooms into the bintree. Uses rand() to determine whos children etc.
	insert(rooms[0], &tree, room1);
	insert(rooms[1], &tree, room2);
	insert(rooms[2], &tree, room3);
	insert(rooms[3], &tree, room4);
	insert(rooms[4], &tree, room5);

	// Begin the quest!!!
	printf("\n\n\n\tWelcome. Ready to play?\n\tPlease enter your name: ");
	scanf("%[^\n]%*c", player);
	printf("\n\n\n");

	// Create a place holder pointer to see what room we are currently at. 
	struct node *current = search(rooms[0], tree);
	int choice;

	// Useful variable used for printing. 
	char printing[300];

	// While we are still in the tree.
	while (current != 0) {

		// Layout of the game interface. 
		strcpy(printing, current->data->description);
		printf("%s", printing);
		printf("\n\n\tWhat do you do?\n\t[1: Go Left\t2: Go Right\t3: Action\t4: Quit\t] => ");
		scanf("%d", &choice);
		printf("\n\n\n\n\n");

		// Decision sections.  
		if (choice == 4){

			// Suicide decision. 
			printf("\n\tReally?\n\t[1: Change your mind\t2: Quit\t] => ");
			scanf("%d", &choice);
			if (choice == 2){
				printf("\n\tFine.\n\tYou killed yourself.\n\tHappy?\n\n\n");
				return(0);
			}

		} else if (choice == 1){

			// Left door choice. Check if room is still dangerous, if it is die. Else proceed.
			strcpy(room1->safe, "\r");
			if (current->data->lethal == 1){
				strcpy(printing, current->data->death);
				printf("%s", printing);
				return(doomed());
			} else if (current->data->lethal == 2){
				strcpy(printing, current->data->death);
				printf("%s", printing);
				current->data->lethal = 0;
			} else {
				strcpy(printing, current->data->safe);
				printf("%s", printing);
				current = current->left;
			}

		} else if (choice == 2){

			// Right door choice. Check if room is still dangerous, if it is die. Else proceed. 
			strcpy(room1->safe, "\r");
			if (current->data->lethal == 1){
				strcpy(printing, current->data->death);
				printf("%s", printing);
				return(doomed());
			} else if (current->data->lethal == 2){
				strcpy(printing, current->data->death);
				printf("%s", printing);
				current->data->lethal = 0;
			} else {
				strcpy(printing, current->data->safe);
				printf("%s", printing);
				current = current->right;
			}

		} else if (choice == 3){

			// Action choice. Resolves the room if lethal, or if important text can be stated. 
			if (current->data->lethal == 1 || current->data->lethal == 2){
				strcpy(printing, current->data->safe);
				printf("%s", printing);
				current->data->lethal = 0;
			} else {
				printf("\n\tWe're done here, lets get moving!");
			}
			strcpy(current->data->description, "\r");
			strcpy(current->data->safe, "\r");

			// Original action description saved for novelty sake. Good times. 
			//printf("\n\tDude.\n\tDidn't you get the memo?\n\tThis is like pre-alpha or something.\n\tQuit pressing buttons that neither of us know what they do.\n");
		
		} else {

			// Emergency catch for input. Retort with sarcasm. 
			printf("*\n\tDeveloper face-palms*\n\tOk.\n\tLets try reading the menu next time.\n\tThe one that's just to the left.\n\tGot it?\n\tAlright everyone, lets try this again!\n");
		}
	}

	// Success, player actually played through the whole thing. 
	printf("\n\tWhelp\n\t%s, you managed to stay sane this whole time and found an exit.\n\tYou may now return to you drab life at your cubicle.\n\tDon't look now, I think your boss is coming up behind you!\n\tOr is that your wife?\n\tRegardless, I was never here.", player);
	printf("\n\n\n\n");
	return(0);
};
/*
Solution for Intermediate Challenge #2
Author: Keydrain
Date:   03/26/15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bintree.h"

struct cell{
	char name[32];
	char description[180];
	 int action;
	char attempt[180];
	char result[180];
};

int main(void){

	struct node *tree;
	int rooms[10];
	rooms[0] = 50;

	for (int i=1; i < 10; i++){
		rooms[i] = rand() % 100;
		//printf("%d\n",rooms[i]);
	}

	struct cell *room1;
	struct cell *room2;
	struct cell *room3;
	struct cell *room4;
	struct cell *room5;

	room1 = malloc(sizeof(struct cell));
	strcpy(room1->name, "room1");
	strcpy(room1->description, "\n\tYou find yourself at an old castle with two doors.\n\tThe gate reads:\n\tTHOSE WHO ENTER, BEWARE. THOSE WHO DON'T ENTER...\n\t(Move along would ya?)\0");
	room1->action = 0;
	strcpy(room1->attempt, "\n\tLets not get carried away here, it's just the beginning of the quest.");
	strcpy(room1->result, "");

	room2 = malloc(sizeof(struct cell));
	strcpy(room2->name, "room2");
	strcpy(room2->description, "\n\tYou find a dragon sleeping in the center of the room.\n\tHe faces a door on his right and another door is located by his tail.");
	room2->action = 1;
	strcpy(room2->attempt, "The dragon wakes up and discovers his next meal has appeared.");
	strcpy(room2->result, "You slew the dragon.\n\tWoot.\n\tCarry on.");

	room3 = malloc(sizeof(struct cell));
	strcpy(room3->name, "room3");
	strcpy(room3->description, "\n\tYou stumble into an empty and silent room with two doors at the opposite side.");
	room3->action = 0;
	strcpy(room3->attempt, "You frantically swing your sword at the air. Nothing happens.");
	strcpy(room3->result, "");

	room4 = malloc(sizeof(struct cell));
	strcpy(room4->name, "room4");
	strcpy(room4->description, "\n\tA treasure chest is in the center of the room with a door on each side.");
	room4->action = 1;
	strcpy(room4->attempt, "\n\tYou opened the chest and discovered a mimic.\n\tAlas, it was too late.\n\tYou were already eaten.");
	strcpy(room4->result, "\b\tYou ignore the chest for some unknown reason...");

	room5 = malloc(sizeof(struct cell));
	strcpy(room5->name, "room5");
	strcpy(room5->description, "\n\tA boy with a fiddle stares at you then glances to the door on his right.");
	room5->action = 1;
	strcpy(room5->attempt, "\n\tYou would leave a defenseless boy in the middle of some castle in who knows where?!?\n\tYou thought he was a monster?\n\tYour the real monster here.\n\tGo back and get him.");
	strcpy(room5->result, "\n\tYou take the boy's hand and walk towards the door.\n\tThe boy looks nervous.\n\tWhat could it mean?\n\tShould you have taken the boy?\n\tIs he safe with you?\n\tIn reality, none of these questions even occur to you.");
	
	insert(rooms[0], &tree, room1);
	insert(rooms[1], &tree, room2);
	insert(rooms[2], &tree, room3);
	insert(rooms[3], &tree, room4);
	insert(rooms[4], &tree, room5);

	//printf("%s\n", room1->description);
	
	printf("\n\tWelcome. Ready to play?");
	getchar();

	struct node *current = search(rooms[0], tree);
	int choice;

	while (current != 0) {
		//printf("--> Debugging: %p\n", current);
		char printing[180];
		//printf("%p\n", current->data);
		strcpy(printing, current->data->description);
		//printf("%p\n", printing);
		printf("%s\n", printing);
		printf("\n\tWhat do you do?\n\t[1: Go Left\t2: Go Right\t3: Action\t4: Quit\t] => ");
		scanf("%d", &choice);
		if (choice == 4){
			printf("\n\tReally?\n\t[1: Change your mind\t2: Quit\t] => ");
			scanf("%d", &choice);
			printf("\n");
			if (choice == 2){
				printf("\tFine.\n\tYou killed yourself.\n\tHappy?\n\n");
				return(0);
			}
		} else if (choice == 1){
			current = current->left;
		} else if (choice == 2){
			current = current->right;
		} else if (choice == 3){
			printf("\n\tDude.\n\tDidn't you get the memo?\n\tThis is like pre-alpha or something.\n\tQuit pressing buttons that neither of us know what they do.\n");
		} else {
			printf("\n\t*Developer face-palms*\n\tOk.\n\tLets try reading the menu next time.\n\tThe one that's just to the left.\n\tGot it?\n\tAlright everyone, lets try this again!\n");
		}
	}

	printf("\n\tYou stayed sane and found an exit.\n\tYou may now return to you drab life at your cubicle.\n\tDon't look now, I think your boss is coming up behind you!\n\tOr is that your wife?\n\tRegardless, I was never here.");

	//printf("--> Debugging: %p\n", current);

	printf("\n\n");
	return(0);
};
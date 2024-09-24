/*
 * Game.c
 *
 *  Created on: 2021¦~12¤ë23¤é
 *      Author: Panda professor
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Game.h"

int WelcomeMessage() {
int choice;
printf("Welcome to the Blackjack game\n");
printf("Are you ready? 1)Yes 2)No\n");
scanf("%d", &choice);
fflush(stdin);

while (choice != 1 && choice != 2) {
		printf("Incorrect. Please enter 1 or 2");
		scanf("%d", &choice);
		fflush(stdin);
	}
    return choice;
}

void InputName(char name[21]) {
     char name1[11];
     char array[2]=" ";

printf("Please input the player's first name (10 characters at most):\n");
scanf("%10s", name);
fflush(stdin);
printf("Please input the player's last name (9 characters at most):\n");
scanf("%9s",name1);
fflush(stdin);
strcat(name,array);
strcat(name,name1);
fflush(stdin);
}

void ShuffleCards(int cards[52]) {
int i, j, buffer;
for (int i = 0; i < 52; i++)
{
	cards[i] = i + 1;
}
for (i = 51; i > 0; i--) {
	j = rand() % i + 1;
	buffer = cards[j];
	cards[j] = cards[i];
	cards[i] = buffer;
}
}

int Face(int n) {
if (n % 13 == 0) {
	return 13;
} else {
	return (n % 13);
}
}

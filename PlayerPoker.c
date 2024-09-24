/*
 * PlayerPoker.c
 *
 *  Created on: 2021¦~12¤ë23¤é
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "SingleComparison.h"
#include "Definitions.h"

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);
	int choice;
	int dealer = 0, player = 1, position = 0;
	choice = WelcomeMessage();
	fflush(stdin);
	char alphabet;
	char name[21];
	int cards[52];
	int i, j;

	Card pcard;
	Card dcard;
	int win;


	while (choice != 1 && choice != 2) {
		printf("Incorrect. Please enter 1 or 2\n");
		scanf("%d", &choice);
		fflush(stdin);
	}

	if (choice == 1) {

		InputName(name);
		fflush(stdin);
		printf("Hello %s\n", name);
		MenuSelection(&alphabet);

	while (alphabet != 'C') {
		switch (alphabet) {
		case 'A':
			ShuffleCards(cards);

			printf("Cards shuffled!\n");
			for (i = 1; i <= 52; i++) {
				if (cards[i] % 13 == 0) {
					printf("%d(13) ", cards[i]);
				} else {
					printf("%d(%d) ", cards[i] % 52, Face(cards[i]));
				}
				if (i % 13 == 0) {
					printf("\n");
				}

			}
			MenuSelection(&alphabet);
			break;

		case 'B':


			Deal1Card(cards, &position, &dealer, &player);
			printf("Deal Card!\n");
			printf("The dealer's card is %d(%d).\n" , dealer, Face(dealer));
			printf("The player's card is %d(%d).\n ", player, Face(player));

			printf("%d cards left!\n", 52 - position);
			if (position == 52) {
				dealer = 0;
				player = 1;
				position = 0;
			}

			pcard = MapCard(player);
			dcard = MapCard(dealer);
			win = winner(dcard,pcard);
			if(win==1){
				printf("%s win!\n",name);
			}
			else if(win==0){
				printf("%s lose!\n",name);
			}

			MenuSelection(&alphabet);
			break;

		default:
			printf("Wrong Selection\n");
			fflush(stdin);
			alphabet = getchar();
			break;
		}
	}

	printf("See You Next Time!");
}
    else if (choice == 2) {
	puts("Goodbye\n");
    }
}






















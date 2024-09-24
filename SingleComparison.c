/*
 * SingleCompaarison.c
 *
 *  Created on: 2021¦~12¤ë23¤é
 *      Author: user
 */
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "SingleComparison.h"
#include "Definitions.h"

void MenuSelection(char *alphabet) {

	printf("A) Shuffle Cards\n");
	printf("B) Play Game\n");
	printf("C) Exit Game\n");
	printf("Please select A, B, or C:\n");
	*alphabet = getchar();
	fflush(stdin);
}

void Deal1Card(const int *const cards, int *position, int *dealer, int *player) {
	*dealer = cards[*position];
	*player = cards[*position + 1];
	*position += 2;
}

Card MapCard(int n) {
	Card card;
	card.face = Face(n);
	if (1 <= n && n <= 13) {
		card.suit = 'S';
	} else if (14 <= n && n <= 26) {
		card.suit = 'H';
	} else if (27 <= n && n <= 39) {
		card.suit = 'D';
	} else if (40 <= n && n <= 52) {
		card.suit = 'C';
	}

	return card;
}

int winner(Card dCard, Card pCard) {
if(pCard.face !=1 && dCard.face !=1) {
	if (pCard.face > dCard.face) {
		return 1;
	}
     else if (pCard.face == dCard.face) {
		if (pCard.suit > dCard.suit) {
			return 1;
		} else {
			return 0;
		}
	} else if(pCard.face == 1 && dCard.face ==1) {
		if(pCard.suit > dCard.suit) {
			return 1;
		} else {
			return 0;
		}
	} else if(pCard.face ==1) {
		return 1;
	} else if(dCard.face ==1) {
		return 0;
	}
}
}

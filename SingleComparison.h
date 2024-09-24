/*
 * SingleComparison.h
 *
 *  Created on: 2021¦~12¤ë23¤é
 *      Author: user
 */

#ifndef SINGLECOMPARISON_H_
#define SINGLECOMPARISON_H_

#include "Definitions.h"

void MenuSelection(char* selection);
void Deal1card(const int *const cards,int *position, int *dealer, int *player);
Card MapCard(int n);
int Winner(Card dCard, Card pCard);

#endif /* SINGLECOMPARISON_H_ */

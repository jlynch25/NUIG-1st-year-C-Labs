#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdarg.h"
#include "stdlib.h"
#include "time.h"

typedef enum S { CLUBS, DIAMONDS, HEARTS, SPADES } SUIT;
char suits[][10] = { "CLUBS", "DIAMONDS", "HEARTS", "SPADES" };

typedef enum F { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE } FACE;
char faces[][10] = { "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING", "ACE" };

typedef struct
{
	SUIT suit;
	FACE face;
} card;

typedef struct
{
	card cards[5];
} hand;

// function deals a random hand of cards - BUT .... same card CANNOT be dealt twice!
// so if same card already in the hand, you would need to draw again
// also, the card cannot appear in another hand either
hand dealHand(hand handsDealt[], int numHandsDealt);

// returns pointer to string containing, for example, "ACE of HEARTS"
char * printCard(card aCard);

// compares the FACE values of two cards (TWO is lowest, ACE is highest)
// returns pointer to string containing name of winner: "You" or "Dealer" (or "Draw" if the face values are the same)
char * compareCards(card yourCard, card dealersCard);

// returns true if the hand contains four ACES
bool fourAces(hand aHand);


void main()
{
	int i = 0;
	hand myHand, dealersHand;
	int seed = time(NULL);
	srand(seed);
	hand hands[10];

	// deal the first hand
	myHand = dealHand(hands, 0);

	// add this new hand to the set of dealt hands
	hands[0] = myHand;

	// deal another hand; let dealHand know what has already been dealt
	dealersHand = dealHand(hands, 1);


	// here you are just comparing each card one at a time in the two hands
	while (i<5)
	{
		printf("card#%d: %s (you) vs. %s (dealer). Winner: %s \n", i + 1, printCard(myHand.cards[i]), printCard(dealersHand.cards[i]), compareCards(myHand.cards[i], dealersHand.cards[i]));
		i++;
	}

	// now try to deal 4 Aces !
	while (1)
	{
		// deal a new hand; assume new deck every time, so nothing dealt already
		myHand = dealHand(hands, 0);

		// does it contain 4 ACES?
		if (fourAces(myHand)) break;
		i++; // keep track of number of hands dealt
	}
	// print out how many hands it took to find 4 aces
	printf("\n\n4 aces found after %d hands \n\n\n", i);
}

// compares the FACE values of two cards (TWO is lowest, ACE is highest)
// returns pointer to string containing name of winner: "You" or "Dealer" (or "Draw" if the face values are the same)
char * compareCards(card yourCard, card dealersCard)
{
	char * sptr;
	sptr = (char *)malloc(10 * sizeof(char));

	// your code goes here
	if (yourCard.face == dealersCard.face)
	{
		sprintf(sptr, "Draw");
	}
	else if (yourCard.face > dealersCard.face)
	{
		sprintf(sptr, "You");
	}
	else
	{
		sprintf(sptr, "Dealer");
	}


	return sptr;
}

// returns pointer to string containing, for example, "ACE of HEARTS"
char * printCard(card aCard)
{
	char * sptr;

	// your code goes here

	sptr = (char *)malloc(20 * sizeof(char));
	sprintf(sptr, "%s of %s", faces[aCard.face], suits[aCard.suit]);

	return  sptr;
}

// function deals a random hand of cards - BUT .... same card CANNOT be dealt twice!
// so if same card already in the hand, you would need to draw again
// also, the card cannot appear in another hand either
hand dealHand(hand handsDealt[], int numHands)
{
	int i, n, check2;
	int found = 0;
	hand newHand;
	int ncards = 5;

	SUIT newSuit;
	FACE newFace;

	// your code goes here

	for (n = 0; n < ncards; n++) {
		newHand.cards[n].suit = enum S(rand() % 4);
		newHand.cards[n].face = enum F(rand() % 13);
	}

	//this for loop checks the cards a 2nd time (only really need to check newHand again)
	//its for the posibile of the same cards in the SAME hand (newHand) after a possibile change of cards
	// in the compare between newHead and handsDealt
	for(check2 =0; check2<=1; check2++){ 
		
	//check cards in newHand
	do {
		for (n = 0; n < ncards; n++) {
			for (i = ncards; i > 0; i--) {
				if (newHand.cards[n].suit == newHand.cards[i].suit && newHand.cards[n].face == newHand.cards[i].face) {
					newHand.cards[n].suit = enum S(rand() % 4);
					newHand.cards[n].face = enum F(rand() % 13);
					found = 1;
					continue;
				}
				else {
					found = 0;
				}
			}
			if (found = 1) {
				continue;
			}
		}
	} while (found = 0);
	
	//check cards in newHand and handsDealt
	do {
		if (numHands = 1) {

			for (n = 0; n < ncards; n++) {
				for (i = 0; i < ncards; i++) {
					if (newHand.cards[n].suit == handsDealt[0].cards[i].suit && newHand.cards[n].face == handsDealt[0].cards[i].face) {
						newHand.cards[n].suit = enum S(rand() % 4);
						newHand.cards[n].face = enum F(rand() % 13);
						found = 1;
						continue;
					}
					else {
						found = 0;
					}
				}
				if (found = 1) {
					continue;
				}
			}

		}
	} while (found = 0);

}


	return newHand;
}

// returns true if the hand contains four ACES
bool fourAces(hand aHand)
{
	int i = 0;
	int numAces = 0;
	bool fourAces = false;

	// your code goes here
	for (i = 0; i < 5; i++)
	{
		if (aHand.cards[i].face == ACE) { numAces++; }
	}
	if (numAces == 4) { fourAces = true; }

	return fourAces;

}
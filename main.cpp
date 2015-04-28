#include <iostream>
#include "deck.h"

using namespace std;

int main()
{
    deck newDeck;

    card* newCard1 = newDeck.drawCard();
    card* newCard2 = newDeck.drawCard();
    card* newCard3 = newDeck.drawCard();

    cout<<newCard1->suite<<", "<<newCard1->value<<endl;
    cout<<newCard2->suite<<", "<<newCard2->value<<endl;
    cout<<newCard3->suite<<", "<<newCard3->value<<endl;

    newDeck.shuffleDeck();

    cout<<endl;

    newDeck.changeSuite("Hearts", "NathansStruggle");

    newDeck.showDeck();

    cout<<endl;

    newDeck.resetDeck();

    newDeck.showDeck();
	
	newDeck.~deck();
}

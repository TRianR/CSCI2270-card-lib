#include "deck.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

deck::deck()
{
    constructDeck();
}

deck::~deck()
{
    //THIS IS BROKEN
    /*
	for(int i = 0; i < cardBuffer.size(); i++){
		delete[] cardBuffer[i];
	}
	while(!cardOrder.empty()){
		cardOrder.pop();
	}
	while(!removedCards.empty()){
		removedCards.pop();
	}
	*/
}

//Creates the deck of cards.
void deck::constructDeck()
{

    string defaultSuits[4] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    for(int i = 0; i < 4; i++){
        suits[i] = defaultSuits[i];
    }
    int suitCount = 1;
    int currentSuit = 0;
    deckSize = 52;

    for(int i = 0; i < 52; i++){
        suitCount++;
        card* newCard = new card;
        newCard->value = suitCount;
        newCard->suit = suits[currentSuit];
        cardBuffer.push_back(newCard);

        if(suitCount == 14){
            currentSuit++;
            suitCount = 1;
        }
    }
}

//Shuffles current cards in the deck
void deck::shuffleDeck()
{
    vector <card*> tempVector = cardBuffer;

    while(cardOrder.empty() != true){
        cardOrder.pop();
    }

    cardBuffer.clear();

    srand(time(NULL));
    int vectorSize = deckSize;

    for(int i = 0; i < deckSize; i++){
        int newPosition = rand() % vectorSize;
        vectorSize--;
        cardOrder.push(tempVector[newPosition]);
        cardBuffer.push_back(tempVector[newPosition]);
        tempVector.erase(tempVector.begin() + newPosition);
    }
    tempVector.clear();
}

//Returns a pointer to a card
card* deck::drawCard()
{
    card* returnValue = cardOrder.front();
    removedCards.push(returnValue);
	cardOrder.pop();
    cardBuffer.erase(cardBuffer.begin());
    deckSize--;

//TRianR ----------------------------------------
    counterDrawn++;
    Drawn.push_back(returnValue);
//TRianR ----------------------------------------

    return returnValue;
}

//TRianR ------------------------------------------
void deck::showCards() {
    if(counterDrawn == 0) {
            cout << "You have yet to draw a card." << endl;
        }
        else {
            cout << "You have drawn " << counterDrawn << " card(s)." << endl;
            for(int i = 0; i < counterDrawn; i++) {
                cout << Drawn[i]->suit << ", " << Drawn[i]->value << endl;
            }
        }
}
//TRianR -------------------------------------------

//Reconstructs a deck of 52 cards
void deck::resetDeck()
{
    cardBuffer.clear();
    while(cardOrder.empty() != true){
        cardOrder.pop();
    }
    // TRianR -------------------------------------
    for(int i = 0; i < counterDrawn; i++) {
        Drawn.pop_back();
    }
    counterDrawn = 0;
    // TRianR -------------------------------------

    constructDeck();
}

//Changes a specified suite of a deck and all following cards
void deck::changeSuit(string oldSuit, string newSuit)
{
    cout<<"swapping"<<endl;
    for(int i = 0; i < 4; i++){
        if(suits[i] == oldSuit){
            suits[i] = newSuit;
        }
    }
    for(int i = 0; i < deckSize; i++){
        if(cardBuffer[i]->suit == oldSuit){
            cardBuffer[i]->suit = newSuit;
        }
    }
}

void deck::showDeck()
{
    for(int i = 0; i < cardBuffer.size(); i++){
        cout<<cardBuffer[i]->suit<<", "<<cardBuffer[i]->value<<endl;
    }
}

// Places the last card back into the deck
void deck::replaceCard(){
	card* replace = removedCards.front();
	cardOrder.push(replace);
	cardBuffer.push_back(replace);
	removedCards.pop();
	deckSize++;

	//TRianR ------------------------------------
	Drawn.pop_back();
	if(counterDrawn > 0) {
        counterDrawn--;
	}
	else{
        counterDrawn = 0;
	}
	//TRianR ------------------------------------
}

//Replaces normal generated deck with deck of user's choosing
void deck::irregularDeck(card* array[], int length){
	for(int i = 0; i < length; i++){
		cardOrder.pop();
		cardOrder.push(array[i]);
		cout<<"Entered "<<array[i]->value<<" of "<<array[i]->suit<<endl;
	}
	return;
}

//Finds the number of how many of a certain card is left
void deck::findRemaining(card* find){
	cout<<"Number or suit?: "<<endl;
	cout<<"Number = 0; Suit = 1"<<endl;
	int input;
	cin>>input;
	switch(input){
		case 0:{
			int numcount = 0;
			for(int i = 0; i < deckSize; i++){
				if(cardBuffer[i]->value == find->value){
					numcount++;
				}
			}
			cout<<"There are "<<numcount<<" cards with a value of "<<find->value<<endl;
			return;
		}
		case 1:{
			int numcount = 0;
			for(int i = 0; i < deckSize; i++){
				if(cardBuffer[i]->suit == find->suit){
					numcount++;
				}
			}
			cout<<"There are "<<numcount<<" cards with a suit of "<<find->suit<<endl;
			return;
		}
	}
}

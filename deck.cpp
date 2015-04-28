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

}

//Creates the deck of cards.
void deck::constructDeck()
{

    string defaultSuites[4] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    for(int i = 0; i < 4; i++){
        suites[i] = defaultSuites[i];
    }
    int suiteCount = 1;
    int currentSuite = 0;
    deckSize = 52;

    for(int i = 0; i < 52; i++){
        suiteCount++;
        card* newCard = new card;
        newCard->value = suiteCount;
        newCard->suite = suites[currentSuite];
        cardBuffer.push_back(newCard);

        if(suiteCount == 14){
            currentSuite++;
            suiteCount = 1;
        }
    }
    shuffleDeck();
}

//Shuffles current cards in the deck
void deck::shuffleDeck()
{
    vector <card*> tempVector = cardBuffer;

    srand(time(NULL));
    int vectorSize = deckSize;

    for(int i = 0; i < deckSize; i++){
        int newPosition = rand() % vectorSize;
        vectorSize--;
        cardOrder.push(tempVector[newPosition]);
        cardBuffer[i] = tempVector[newPosition];
        tempVector.erase(tempVector.begin() + newPosition);
    }

    //for(int i = 0; i < deckSize; i++){
        //cout<<cardOrder.front()->suite<<", "<<cardOrder.front()->value<<endl;
        //cardOrder.pop();
        //cout<<cardBuffer[i]->suite<<", "<<cardBuffer[i]->value<<endl;
    //}

}

//Returns a pointer to a card
card* deck::drawCard()
{
    card* returnValue = cardOrder.front();
    cardOrder.pop();
    cardBuffer.erase(cardBuffer.begin());
    deckSize--;
    return returnValue;
}

//Reconstructs a deck of 52 cards
void deck::resetDeck()
{
    cout<<"clearing"<<endl;
    cardBuffer.clear();
    for(int i = 0; i < cardOrder.size(); i++){
        cardOrder.pop();
    }
    constructDeck();
    cout<<"reset complete"<<endl;
}

//Changes a specified suite of a deck and all following cards
void deck::changeSuite(string oldSuite, string newSuite)
{
    cout<<"swapping"<<endl;
    for(int i = 0; i < 4; i++){
        if(suites[i] == oldSuite){
            suites[i] = newSuite;
        }
    }
    for(int i = 0; i < deckSize; i++){
        if(cardBuffer[i]->suite == oldSuite){
            cardBuffer[i]->suite = newSuite;
        }
    }
}

void deck::showDeck()
{
    for(int i = 0; i < cardBuffer.size(); i++){
        cout<<cardBuffer[i]->suite<<", "<<cardBuffer[i]->value<<endl;
    }
}

// Takes a number and a suit, and replaces it with another number and suit. Will do for any card in the deck
void deck::replaceCard(int number1, string suit1, int number2, string suit2){
	cout<<"Replace all or just one?: "<<endl;
	cout<<"All = 0"<<endl<<"One = 1"<<endl;
	int decision;
	cin>>decision;
	switch(decision){
		case 1:{
			for(int i = 0; i < cardBuffer.size(); i++){
				if(cardBuffer[i]->value == number1 and cardBuffer[i]->suite == suit1){
					cardBuffer[i]->value = number2;
					cardBuffer[i]->suite = suit2;
					cout<<number1<<" of "<<suit1<<" replaced with "<<number2<<" of "<<suit2<<endl;
					return;
				}
			}
			cout<<"Card not found!"<<endl;
			return;
		}
		case 2:{
			int replaced = 0;
			for(int i = 0; i < cardBuffer.size(); i++){
				if(cardBuffer[i]->value == number1 and cardBuffer[i]->suite == suit1){
					cardBuffer[i]->value = number2;
					cardBuffer[i]->suite = suit2;
					cout<<number1<<" of "<<suit1<<" replaced with "<<number2<<" of "<<suit2<<endl;
					replaced++;
				}
			}
			cout<<"All cards found were replaced; total replaced: "<<replaced;
			return;
		}
	}
}




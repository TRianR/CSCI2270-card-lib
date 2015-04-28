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


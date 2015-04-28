#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <queue>

struct card
{
    int value;
    std::string suit;
};

class deck
{
    public:
        deck();
        virtual ~deck(); //Joaquin
        card* drawCard(); //Daniel
        void shuffleDeck(); //Daniel
        void replaceCard(); //Joaquin
        void showDeck(); //Daniel
        void resetDeck(); //Daniel
        void irregularDeck(card* arrayOfNewCards[], int l); //Joaquin
        void changeSuit(std::string oldSuit, std::string newSuit); //Daniel
	void findRemaining(card* find); //Joaquin

    protected:
    private:
        void constructDeck();

        int deckSize = 52;
        std::string suits[4] = {"Hearts", "Clubs", "Diamonds", "Spades"};
        std::vector<card*> cardBuffer;
        std::queue<card*> cardOrder;
        std::queue<card*> removedCards;
};

#endif // DECK_H

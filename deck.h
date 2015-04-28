#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <queue>

struct card
{
    int value;
    std::string suite;
};

class deck
{
    public:
        deck();
        virtual ~deck(); //Daniel
        card* drawCard(); //Daniel
        void shuffleDeck(); //Daniel
        void replaceCard(int number1, std::string suit1, int number2, std::string suit2); //Joaquin
        void showDeck(); //Daniel
        void resetDeck(); //Daniel
        void irregularDeck(card arrayOfNewCards[]); //Joaquin
        void changeSuite(std::string oldSuite, std::string newSuite); //Daniel
        //add two more functions
    protected:
    private:
        void constructDeck();

        int deckSize = 52;
        std::string suites[4] = {"Hearts", "Clubs", "Diamonds", "Spades"};
        std::vector<card*> cardBuffer;
        std::queue<card*> cardOrder;
        std::queue<card*> removedCards;
};

#endif // DECK_H

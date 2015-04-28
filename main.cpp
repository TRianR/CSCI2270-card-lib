#include <iostream>
#include "deck.h"

using namespace std;

int main()
{
    deck newDeck;
    while(true){
        cout<<"|======Testing Program======|"<<endl;
        cout<<"1. Shuffle Deck"<<endl;
        cout<<"2. Draw Card"<<endl;
        cout<<"3. Replace Card"<<endl;
        cout<<"4. Reset Deck"<<endl;
        cout<<"5. Show Deck"<<endl;
        cout<<"6. Change Suit"<<endl;
        cout<<"7. Custom Deck"<<endl;
        cout<<"8. Find Remaining"<<endl;
        cout<<"9. Quit"<<endl;

        int userInput;
        cin >> userInput;

        if(userInput == 1){
            newDeck.shuffleDeck();
        }
        if(userInput == 2){
            card* newCard1 = newDeck.drawCard();
            cout<<newCard1->suit<<", "<<newCard1->value<<endl;
        }
        if(userInput == 3){
            newDeck.replaceCard();
        }
        if(userInput == 4){
            newDeck.resetDeck();
        }
        if(userInput == 5){
            newDeck.showDeck();
        }
        if(userInput == 6){
            string userInput2;
            string userInput3;

            cout<<"Old suit?"<<endl;
            cin >> userInput2;
            cout<<"New suit?"<<endl;
            cin >>userInput3;

            newDeck.changeSuit(userInput2, userInput3);
        }
        if(userInput == 7){
        	cout<<"Nothing here yet!"<<endl;
        }
        if(userInput == 8){

            string userInput4;
            string userInput5;

            cout<<"Number"<<endl;
            cin >> userInput4;
            cout<<"Suit"<<endl;
            cin >> userInput5;

            card *testCard = new card;
            testCard->suit = "Hearts";
            testCard->value = 3;
            newDeck.findRemaining(testCard);
            delete testCard;
        }
        if(userInput == 9){
            return 0;
        }
    }
}

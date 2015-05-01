#include <iostream>
#include "deck.h"

using namespace std;

int main()
{
    //vector<card*> Drawn; //TRianR
    //int counterDrawn = 0; //TRianR

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
        cout<<"9. Show Drawn Card(s)"<<endl; //TRianR
        cout<<"10. Quit"<<endl;
        int userInput;
        cin >> userInput;

        if(userInput == 1){
            newDeck.shuffleDeck();
        }
        if(userInput == 2){
            card* newCard1 = newDeck.drawCard();
            cout<<newCard1->suit<<", "<<newCard1->value<<endl;
            //counterDrawn++; // TRianR
            //Drawn.push_back(newCard1); //TRianR
        }
        if(userInput == 3){
            newDeck.replaceCard();
            //Drawn.pop_back(); //TRianR
            //counterDrawn--; //TRianR
        }
        if(userInput == 4){
            newDeck.resetDeck();
            //TRianR ----------------
            //for(int i = 0; i < counterDrawn; i++) {
                //Drawn.pop_back();
            //}
            //counterDrawn = 0;
            //TRianR ----------------
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
        if(userInput == 10){
            return 0;
        }
        //TRianR   ------------------------
        if(userInput == 9) {
                newDeck.showCards();
            /*
            if(Drawn.size() == 0) {
                cout << "You have yet to draw a card." << endl;
            }
            else {
                cout << "You have drawn " << counterDrawn << " card(s)." << endl;
                for(int i = 0; i < counterDrawn; i++) {
                    cout << Drawn[i]->suit << ", " << Drawn[i]->value << endl;
                }
            }
        */
        //TRianR   --------------------------
        }
    }
}

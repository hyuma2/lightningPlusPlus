#include <iostream>
using namespace std;
int main(){
    float rng;
    int position; int advantage = 0; int npcAdvantage = 0; int round = 1; 
    bool success;
    char cont;


    srand(time(0));
    cout << "\nWelcome to Lightning. Score two shots in a row before your opponent scores to win! Enter (y) to start: ";
    cin >> cont;

    if(cont != 'y'){
        cout << "Thanks for playing!" << endl; //0 0 
        }
    else{
        while(abs(advantage - npcAdvantage) <= 2){

            //Win Conditions
            if (advantage - npcAdvantage == 2) //Positioned before "Score" loop so Round is not displayed and NPC does not attempt to score.
            {
                cout << "========================================================================================================\n";   
                cout << "                                   You win! Thanks for playing!\n";
                cout << "========================================================================================================\n";
                break;
            }
            if (npcAdvantage - advantage == 2)
            {
                cout << "========================================================================================================\n";
                cout << "                              Your opponent wins. Better luck next time!\n";
                cout << "========================================================================================================\n";
                break;
            }


            //Start-of-turn Prompt
            cout << 
            "========================================================================================================\n" <<
            " __________________ \n" <<
            "|       4          |\n" <<
            "|_________         |\n" <<
            "|   1      \\    5  |\n"<<
            "|:@         3      |\n" <<
            "|_________ /       |\n" <<
            "|    2             |\n" <<
            "|__________________|\n" <<
            "\nEnter a position using numbers 1-5. The lower the number, the closer it is to the hoop: ";
            cin >> position;

            //Player's Turn
            if (position > 0 && position <= 5)
            {
                cout << 
                "\n========================================================================================================" <<
                "\nRound " << round << ":\n";
                rng = (rand() % 100) + 1; //Number from 1 to 100
                success = rng <= 100 - position * 10;
                if (success)
                {
                    cout << "\nYou scored!\n";
                    ++advantage;
                    //--npcAdvantage;
                } 
                else
                {
                    cout << "\nYou missed!\n";
                }
            }  
            else
            {
                cout << "Please enter a number between 1 and 5.\n\n";
                break; //Temporary fix to Infinite Loop bug
            }


            //Opponent's turn
            if(abs(advantage - npcAdvantage) == 2){
                continue;
            }
            rng = rand() % 100;
            success = rng <= 100 - position * 10;
            cout << "\nYour opponent shoots from the spot you chose and ";
            if (success)
            {
                cout <<"scores.\n\n";
                    ++npcAdvantage;
                    //--advantage;
            }
            else
            {
                cout << "misses.\n\n";
            }


            cout << "You: " << advantage << " NPC: " << npcAdvantage << endl;
            ++round;
        }
    }
    return (0);
}
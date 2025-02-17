#include <iostream>

using namespace std;

int main()
{
    //FIXME: Offer 5 options to shoot from
    float rng;
    int position = 0;
    bool success;
    char cont;
    int advantage = 0;
    int npcAdvantage = 0;
    int round = 1;

    //Advantage: When you score, the other person has to score before you score twice to stay in, 
    //otherwise they lose. If the person before you scores, you have to score before they score agai to stay in.
    srand(time(0));
    cout << "\nWelcome to Lightning. Score two shots in a row before your opponent scores to win! Enter (y) to start: ";
    cin >> cont;
    if (cont != 'y')
    {
        cout << "Thanks for playing!" << endl;
    } 
    else
    {
        while (advantage <= 2 || npcAdvantage <= 2)
        {
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
            if (!(cin >> position))
            {
                cout << "Please enter a number between 1 and 5.\n\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            if (position > 0 && position <= 5)
            {
                cout << 
                "\n========================================================================================================" <<
                "\nRound " << round << ":\n";
                rng = rand() % 100;
                success = rng <= 100 - position * 10;
                if (success)
                {
                    cout << "\nYou scored!\n";
                    ++advantage;
                    --npcAdvantage;
                } 
                else
                {
                    cout << "\nYou missed!\n";
                }
                ++round;
            }  
            else
            {
                cout << "Please enter a number between 1 and 5.\n\n";
                continue;
            }
            rng = rand() % 100;
            success = rng <= 100 - position * 10;
            cout << "\nYour opponent shoots from the spot you chose and ";
            if (success)
            {
                cout << "scores.\n\n";
                    //++npcAdvantage;
                    //--advantage;
            }
            else
            {
                cout << "misses.\n\n";
            }
            if (advantage == 2)
            {
                cout << "========================================================================================================\n";
                cout << "\n                               You win! Thanks for playing!\n";
                cout << "========================================================================================================\n";
                break;
            }
            if (npcAdvantage == 2)
            {
                cout << "========================================================================================================\n";
                cout << "                         \nYour opponent wins. Better luck next time!\n";
                cout << "========================================================================================================\n";
                break;
            }
        }
    }
    return 0;
}

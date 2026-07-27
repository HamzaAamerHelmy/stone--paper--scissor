#include <iostream>
using namespace std;

enum enChoices
{
    stone = 1,
    paper = 2,
    scissor = 3
};

void readNumberOfRounds(int &numberOfRounds)
{
    int userInput = 0;
    do
    {

        cout << "How Elements do you want to enter(max 10): ";
        cin >> userInput;
        cout << endl;

        if (userInput > 10)
        {
            cout << "Try Again!" << endl;
            cout << "Please enter a valid Number.." << endl;
            continue;
        }
        numberOfRounds = userInput;
        return;
    } while (userInput > 10);
}

enChoices readThisRound(enChoices choices, int numberOfThisRound)
{
    int userChoice = 0;
    do
    {  
        cout << "Round [" << numberOfThisRound << "] begins: " << endl << endl;
        cout << "Enter Your Choice: [1]stone, [2] paper, [3] scissor: ";
        cin >> userChoice;
    
        choices = (enChoices)userChoice;
    
        if (userChoice != enChoices::stone && userChoice != enChoices::paper && userChoice != enChoices::scissor)
        {
            cout << "Wrong Input!" << endl;
            continue;
        }
        return choices;
    }while (userChoice == enChoices::stone && userChoice == enChoices::paper && userChoice == enChoices::scissor);

    return choices;
}

int main()
{
    enChoices choices;

    int numberOfRounds = 0;

    readNumberOfRounds(numberOfRounds);

    return 0;
}
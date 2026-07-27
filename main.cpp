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
    }while (userChoice != enChoices::stone && userChoice != enChoices::paper && userChoice != enChoices::scissor);

    return choices;
}

enChoices fillComputerInput()
{
    int randomChoice = rand() % (enChoices::scissor - enChoices::stone) + enChoices::stone;

    return (enChoices)randomChoice;
}

void StartGame()
{
    srand((unsigned)time(NULL));
    
    enChoices choices;

    int numberOfRounds = 0;

    readNumberOfRounds(numberOfRounds);

    int playerChoice = readThisRound(choices, 1);

    cout << playerChoice << endl;

    cout << fillComputerInput() << endl;
}

int main()
{
    StartGame();

    return 0;
}
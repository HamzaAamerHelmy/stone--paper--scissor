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

enChoices readPlayerInputOfThisRound(enChoices choices, int numberOfThisRound)
{
    int userChoice = 0;
    do
    {
        cout << "Round [" << numberOfThisRound << "] begins: " << endl
             << endl;
        cout << "Enter Your Choice: [1]stone, [2] paper, [3] scissor: ";
        cin >> userChoice;
        cout << "\n";

        choices = (enChoices)userChoice;

        if (userChoice != enChoices::stone && userChoice != enChoices::paper && userChoice != enChoices::scissor)
        {
            cout << "Wrong Input!" << endl;
            continue;
        }
        return choices;
    } while (userChoice != enChoices::stone && userChoice != enChoices::paper && userChoice != enChoices::scissor);

    return choices;
}

enChoices fillComputerInput()
{
    int randomChoice = rand() % ((enChoices::scissor + 1) - enChoices::stone) + enChoices::stone;

    return (enChoices)randomChoice;
}

string winnerRules(enChoices choiceOfPlayer, enChoices choiceOfComputer)
{
    if (choiceOfPlayer == choiceOfComputer)
    {
        return "Equal";
    }
    else if (choiceOfPlayer == enChoices::stone && choiceOfComputer == enChoices::paper)
    {
        return "Computer";
    }
    else if (choiceOfPlayer == enChoices::stone && choiceOfComputer == enChoices::scissor)
    {
        return "Player";
    }
    else if (choiceOfPlayer == enChoices::paper && choiceOfComputer == enChoices::stone)
    {
        return "Player";
    }
    else if (choiceOfPlayer == enChoices::paper && choiceOfComputer == enChoices::scissor)
    {
        return "Computer";
    }
    else if (choiceOfPlayer == enChoices::scissor && choiceOfComputer == enChoices::stone)
    {
        return "Computer";
    }
    else if (choiceOfPlayer == enChoices::scissor && choiceOfComputer == enChoices::paper)
    {
        return "Player";
    }
    return "Wrong";
}

void printDetailsOfThisRound(int numberOfThisRound, enChoices choiceOfPlayer, enChoices choiceOfComputer)
{
    cout << "____________________Round[" << numberOfThisRound << "]____________________" << endl
         << endl;
    switch (choiceOfPlayer)
    {
    case enChoices::stone:
        cout << "Player Choice: Stone" << endl;
        break;
    case enChoices::paper:
        cout << "Player Choice: Paper" << endl;
        break;
    case enChoices::scissor:
        cout << "Player Choice: Scissor" << endl;
        break;
    default:
        break;
    }

    switch (choiceOfComputer)
    {
    case enChoices::stone:
        cout << "Computer Choice: Stone" << endl;
        break;
    case enChoices::paper:
        cout << "Computer Choice: Paper" << endl;
        break;
    case enChoices::scissor:
        cout << "Computer Choice: Scissor" << endl;
        break;
    default:
        break;
    }

    cout << "Round Winner   : ";
    if (winnerRules(choiceOfPlayer, choiceOfComputer) == "Player")
    {
        cout << " Player" << endl;
    }
    else if (winnerRules(choiceOfPlayer, choiceOfComputer) == "Computer")
    {
        cout << "[Computer]" << endl;
    }
    else if (winnerRules(choiceOfPlayer, choiceOfComputer) == "Equal")
    {
        cout << "No Winner" << endl;
    }
    cout << "__________________________________________________" << endl;
}

void StartGame()
{
    srand((unsigned)time(NULL));

    enChoices choices;

    int numberOfRounds = 0;

    readNumberOfRounds(numberOfRounds);

    enChoices choiceOfPlayer = readPlayerInputOfThisRound(choices, 1);

    enChoices choiceOfComputer = fillComputerInput();

    printDetailsOfThisRound(1, choiceOfPlayer, choiceOfComputer);
}

int main()
{
    StartGame();

    return 0;
}
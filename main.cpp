#include <iostream>
#include <windows.h>
using namespace std;

enum enChoices
{
    stone = 1,
    paper = 2,
    scissor = 3
};

int scoreOfPlayer = 0;
int scoreOfComputer = 0;
int scoreOfDraw = 0;

void readNumberOfRounds(int &numberOfRounds)
{
    int userInput = 0;
    do
    {

        cout << "Enter Number Of Rounds(max 10): ";
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

enChoices readPlayerInputOfThisRound(enChoices choiceOfPlayer, int numberOfThisRound)
{
    int userChoice = 0;
    do
    {
        cout << "Round [" << numberOfThisRound << "] begins: " << endl
             << endl;
        cout << "Enter Your Choice: [1]stone, [2] paper, [3] scissor: ";
        cin >> userChoice;
        cout << "\n";

        choiceOfPlayer = (enChoices)userChoice;

        if (userChoice != enChoices::stone && userChoice != enChoices::paper && userChoice != enChoices::scissor)
        {
            cout << "Wrong Input!" << endl;
            continue;
        }
        return choiceOfPlayer;
    } while (userChoice != enChoices::stone && userChoice != enChoices::paper && userChoice != enChoices::scissor);

    return choiceOfPlayer;
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

void printPlayerChoice(enChoices choiceOfPlayer, string textOfPlayer)
{
    string space = "";

    if (textOfPlayer == "Player")
    {
        space = "  ";
    }

    switch (choiceOfPlayer)
    {
    case enChoices::stone:
        cout << textOfPlayer << " Choice" << space << ": Stone" << endl;
        break;
    case enChoices::paper:
        cout << textOfPlayer << " Choice" << space << ": Paper" << endl;
        break;
    case enChoices::scissor:
        cout << textOfPlayer << " Choice" << space << ": Scissor" << endl;
        break;
    default:
        break;
    }
}

void printDetailsOfThisRound(int numberOfThisRound, enChoices choiceOfPlayer, enChoices choiceOfComputer)
{
    cout << "____________________Round[" << numberOfThisRound << "]____________________" << endl
         << endl;
    printPlayerChoice(choiceOfPlayer, "Player");
    printPlayerChoice(choiceOfComputer, "Computer");

    cout << "Round Winner   : ";
    if (winnerRules(choiceOfPlayer, choiceOfComputer) == "Player")
    {
        system("color 2F");
        cout << "[Player]" << endl;
        scoreOfPlayer++;
    }
    else if (winnerRules(choiceOfPlayer, choiceOfComputer) == "Computer")
    {
        system("color 4F");
        // play a bill when lose
        cout << "\a";
        cout << "[Computer]" << endl;
        scoreOfComputer++;
    }
    else if (winnerRules(choiceOfPlayer, choiceOfComputer) == "Equal")
    {
        system("color 6F");
        cout << "[No Winner]" << endl;
        scoreOfDraw++;
    }
    cout << "__________________________________________________" << endl
         << endl;
}

void readAndPrintMultipleRounds(int numberOfRounds, enChoices choiceOfPlayer, enChoices choiceOfComputer)
{
    for (int i = 1; i <= numberOfRounds; i++)
    {
        choiceOfPlayer = readPlayerInputOfThisRound(choiceOfPlayer, i);

        choiceOfComputer = fillComputerInput();

        printDetailsOfThisRound(i, choiceOfPlayer, choiceOfComputer);
    }
}

void clearScreen()
{
    system("cls");
}

bool restartGame()
{
    string userInput = "";

    cout << "                   Do you want to Play Again (Y: yes, any Key: no): ";
    cin >> userInput;

    if (userInput == "y" || userInput == "Y")
    {
        clearScreen();
        return true;
    }
    return false;
}

void printGameOver(int numberOfRounds, enChoices choiceOfPlayer, enChoices choiceOfComputer)
{
    cout << "                   _______________________________________________________________________________________________" << endl
         << endl;
    cout << "                                                 +++     G a m e O v e r     +++" << endl;
    cout << "                   _______________________________________________________________________________________________" << endl
         << endl;
    cout << "                   _______________________________________ [Game Results] ________________________________________" << endl
         << endl;
    cout << "                   Game Rounds        : " << numberOfRounds << endl;

    cout << "                   Player won times   : " << scoreOfPlayer << endl;

    cout << "                   Computer won times : " << scoreOfComputer << endl;

    cout << "                   Draw times         : " << scoreOfDraw << endl;

    cout << "                   Final Winner       : ";

    if (scoreOfPlayer == scoreOfComputer)
    {
        cout << "No Winner" << endl
             << endl;
    }
    else if (scoreOfPlayer > scoreOfComputer)
    {
        cout << "Player" << endl
             << endl;
    }
    else if (scoreOfComputer > scoreOfPlayer)
    {
        cout << "Computer" << endl
             << endl;
    }

    cout << "                   _______________________________________________________________________________________________" << endl
         << endl;
    if (restartGame())
    {
        
    }
    else
    {
        return;
    }
}

void StartGame()
{
    // reset system screen
    system("color 0F");
    srand((unsigned)time(NULL));

    enChoices choiceOfPlayer;

    enChoices choiceOfComputer;

    int numberOfRounds;

    readNumberOfRounds(numberOfRounds);

    readAndPrintMultipleRounds(numberOfRounds, choiceOfPlayer, choiceOfComputer);

    printGameOver(numberOfRounds, choiceOfPlayer, choiceOfComputer);
}

int main()
{
    StartGame();

    return 0;
}
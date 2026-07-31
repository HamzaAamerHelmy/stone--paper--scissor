#include <iostream>
#include <windows.h>
using namespace std;

void mySleep(int duration)
{
    Sleep(duration);
}

void clearScreen()
{
    system("cls");
}

void printWelcome()
{
    cout << "___________________________Welcome To     ";
    mySleep(1000);
    cout << "S T O N E ";
    mySleep(1000);
    cout << "-- P A P E R";
    mySleep(1000);
    cout << " -- S C I S S O R";
    mySleep(1000);
    cout << "     Game___________________________" << endl;
    mySleep(1000);
    cout << "Please Wait ..." << endl;
    mySleep(3000);

    clearScreen();
}

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

        cout << "Enter Number Of Rounds Or Press E/e to close Program(max 10): ";
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

enChoices readPlayerInputOfThisRound(enChoices choiceOfPlayer, int numberOfThisRound, int numberOfRounds)
{
    int userChoice = 0;
    do
    {
        cout << "Round [" << numberOfThisRound << "/" << numberOfRounds << "] begins: " << endl
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
        choiceOfPlayer = readPlayerInputOfThisRound(choiceOfPlayer, i, numberOfRounds);

        choiceOfComputer = fillComputerInput();

        printDetailsOfThisRound(i, choiceOfPlayer, choiceOfComputer);
    }
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

void playLoseSound()
{
    mySleep(1000);

    Beep(650, 250);
    mySleep(70);

    Beep(500, 250);
    mySleep(70);

    Beep(300, 900);
}

void playDrawSound()
{
    mySleep(1000);

    Beep(523, 150);
    mySleep(30);
    Beep(659, 150);
    mySleep(30);
    Beep(523, 250);
}

void playWinSound()
{
    mySleep(1000);

    Beep(784, 120);
    mySleep(30);
    Beep(988, 120);
    mySleep(30);
    Beep(1175, 180);
    mySleep(30);
    Beep(1568, 350);
}

void printGameOver(int numberOfRounds, enChoices choiceOfPlayer, enChoices choiceOfComputer)
{
    string finalWinner = "";
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
        finalWinner = "No Winner";
    }
    else if (scoreOfPlayer > scoreOfComputer)
    {
        finalWinner = "Player";
    }
    else if (scoreOfComputer > scoreOfPlayer)
    {
        finalWinner = "Computer";
    }
    
    cout << finalWinner << endl << endl;
    
    cout << "                   _______________________________________________________________________________________________" << endl
    << endl;
    
    if (finalWinner == "No Winner")
    {
        system("color 6F");
        playDrawSound();
    }
    else if (finalWinner == "Player")
    {
        system("color 2F");
        playWinSound();
    }
    else
    {
        system("color 4F");
        playLoseSound();
    }
    
    if (restartGame())
    {
        system("color 0F");
        
        scoreOfPlayer = 0;
        scoreOfComputer = 0;
        scoreOfDraw = 0;

        readNumberOfRounds(numberOfRounds);
        readAndPrintMultipleRounds(numberOfRounds, choiceOfPlayer, choiceOfComputer);
        printGameOver(numberOfRounds, choiceOfPlayer, choiceOfComputer);
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

    printWelcome();

    readNumberOfRounds(numberOfRounds);

    readAndPrintMultipleRounds(numberOfRounds, choiceOfPlayer, choiceOfComputer);

    printGameOver(numberOfRounds, choiceOfPlayer, choiceOfComputer);
}

int main()
{
    StartGame();

    return 0;
}
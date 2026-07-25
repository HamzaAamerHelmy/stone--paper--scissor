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

int main()
{
    

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

string getOs()
{
#ifdef _WIN32
    return "windows";
#elif _WIN64
    return "windows";
#elif __APPLE__ || __MACH__
    return "mac";
#elif __linux__
    return "linux";
#elif __FreeBSD__
    return "linux";
#elif __unix || __unix__
    return "linux";
#else
    return "other";
#endif
}

int randomNumber(int start, int end)
{
    return start + (std::rand() % (end - start + 1));
}

int randomRange(int start, int range)
{
    return start + range;
}

int main()
{

    bool play = true;
    string userPlayInput = "";
    int start = 1, end = 100;

    int gamePlayCount = 0, totalGuessCount = 0;
    string userGuess;
    int userGuessInt;
    while (play)
    {
        int guessNumber = 0;
        gamePlayCount++;
        // Generate a random range
        cout << "Generating a random range..";
        start = rand() % (end - 0 + 1) + 0;
        end = randomRange(start, 30);
        cout << "New range is " << start << " - " << end << ".\n";

        // Generate a number to guess
        guessNumber = randomNumber(start, end);

        // Clear the screen
        if (getOs() == "windows")
        {
            system("cls");
        }
        else
            system("clear");

        // Ask the user for the guess
        cout << "Number generated. Please guess a number between " << start << " and " << end << "\n> ";

        // Run the code till the user guess the number
        while (userGuessInt != guessNumber)
        {
            cin >> userGuess;
            try
            {
                userGuessInt = stoi(userGuess);
            }
            catch (exception &e)
            {
                cout << "Please enter a valid number!";
                continue;
            }
            totalGuessCount++;
            string high_low = "high";
            if (userGuessInt < guessNumber)
                high_low = "low";
            if (userGuessInt != guessNumber)
                cout << "The number you guess was too " << high_low << "\n> ";
        }

        cout << "========\n";
        cout << "Your stats:\n";
        cout << "Total Game play: " << gamePlayCount << "\n";
        cout << "Total guesses: " << totalGuessCount << "\n";
        cout << "\n";
        cout << "Do you want to play again? [Y/N]\n>";

        cin >> userPlayInput;

        // Check if the user wants to play or not

        if (userPlayInput == "n" || userPlayInput == "N")
            play = false;
    }
    cout << "Bye!";
}

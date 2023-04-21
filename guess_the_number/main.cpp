#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{

    bool play = true;
    int start = 0, end = 50;


    int gamePlayCount = 0, totalGuessCount = 0;
    int guessNumber = 0;
    while (play)
    {


        // Generate a random range 
        cout << "Generating a random range..";
        start = rand();
        end = randomRange(start,30);
        cout << "New range is "<<start<<" - "<<end<<".";

        // Generate a number to guess
        guessNumber = randomNumber(start,end);

        if(getOs() == "windows") system('cls');
        else {
            system('clear');
        }

        // Ask the user for the guess
        cout <<"Number generated. Please guess a number between "<<start<<" and "<<end<<".";



    }
}

int randomNumber(int start, int end)
{
    return start + (std::rand() % (end - start + 1));
}

int randomRange(int start, int range ){
    return start+range;
}

string getOs(){
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
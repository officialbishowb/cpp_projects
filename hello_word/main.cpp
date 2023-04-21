#include <iostream>
using namespace std;

int main()
{
    int amount = 1;
    cout << "How many times (number) do you want to print 'Hello Word' ?: ";
    cin >> amount;

    cout << "Printing 'Hello World' " << amount << " times\n--------------------\n";
    for (int i = 0; i < amount; i++)
    {
        cout << "Hello World\n";
    }
    return 0;
}
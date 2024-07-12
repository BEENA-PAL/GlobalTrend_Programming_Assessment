// Write a function to check if a given string contains only alphabetic characters.The function should return true if the string contains only alphabetic characters, and false otherwise.\


#include <iostream>
#include <string>
using namespace std;

// Function to check if a string contains only alphabetic characters
bool containsOnlyAlphabets(const string &str)
{
    // Iterate through each character in the string
    for (char ch : str)
    {
        // Check if the character is not an alphabet
        if (!isalpha(ch))
        {
            return false;
        }
    }
    // All characters are alphabetic
    return true;
}

int main()
{
    string input;

    // Prompt user for input
    cout << "Enter a string: ";
    getline(cin, input);

    // Check if the string contains only alphabetic characters
    if (containsOnlyAlphabets(input))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
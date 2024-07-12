// Write a function to compute the sum of the digits of a given number.The function should return the sum of the digits of the number.

#include <iostream>
using namespace std;

// Function to compute the sum of digits of a given number
int sumOfDigits(int num)
{
    int sum = 0;

    // Iterate through each digit of the number
    while (num > 0)
    {
        // Extract the last digit
        int digit = num % 10;
        // Add the digit to the sum
        sum += digit;
        // Remove the last digit from the number
        num /= 10;
    }

    return sum;
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    // Calculate the sum of digits
    int result = sumOfDigits(number);

    // Output the result
    cout << "Sum of digits of " << number << " is: " << result << endl;

    return 0;
}
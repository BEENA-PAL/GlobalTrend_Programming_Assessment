// Write a function to find the factorial of a given number.The function should return the factorial of the number.

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate factorial of a number using dynamic programming
unsigned long long factorial(int n)
{
    // Initialize a vector to store factorial values
    vector<unsigned long long> dp(n + 1, 1);

    // Compute factorial values from 2 to n
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] * i;
    }

    // Return the factorial of n
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter a number to find factorial: ";
    cin >> n;

    // Calculate factorial using the factorial function
    unsigned long long fact = factorial(n);

    // Output the factorial
    cout << "Factorial of " << n << " is: " << fact << endl;

    return 0;
}

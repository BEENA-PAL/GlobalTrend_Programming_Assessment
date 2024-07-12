// Write a function to find the greatest common divisor (GCD) of two numbers. The function should return the GCD of a and b.

#include <bits/stdc++.h>
using namespace std;

// Function to find the Greatest Common Divisor (GCD) of two numbers using Euclid's algorithm
int gcd(int a, int b)
{
    // Base case: if b is 0, return a
    if (b == 0)
    {
        return a;
    }
    // Recursive case: compute gcd(b, a % b)
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // Calculate the GCD of a and b using the gcd function
    int result = gcd(a, b);

    // Output the result
    cout << "GCD of " << a << " and " << b << " is: " << result << endl;

    return 0;
}

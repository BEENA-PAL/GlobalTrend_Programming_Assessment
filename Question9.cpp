// Write a function to find the maximum difference between any two elements in an array.The function should return the maximum difference between any two elements in the array.

#include <bits/stdc++.h>
using namespace std;

int maxDifference(vector<int> &nums)
{
    // Handle edge case: if the array has less than 2 elements, return 0
    if (nums.size() < 2)
    {
        return 0;
    }

    // Initialize variables to track minimum and maximum values
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    // Traverse the array to find the minimum and maximum values
    for (int num : nums)
    {
        if (num < minVal)
        {
            minVal = num;
        }
        if (num > maxVal)
        {
            maxVal = num;
        }
    }
    int maxDiff = maxVal - minVal;

    return maxDiff;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    // Calculate the maximum difference between any two elements in the array
    int maxDiff = maxDifference(nums);

    // Output the result
    cout << "Maximum difference between any two elements: " << maxDiff << endl;

    return 0;
}

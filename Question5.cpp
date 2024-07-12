// Write a function to rotate an array to the right by k steps.The function should modify the array in place to achieve the rotation.

#include <iostream>
#include <vector>
using namespace std;

// Function to reverse elements in the array from index 'start' to 'end'
void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate the array 'arr' to the right by 'k' times
void rotateArray(int arr[], int n, int k)
{
    k = k % n; // Calculate effective rotations if k > n

    // Reverse the last 'k' elements
    reverseArray(arr, n - k, n - 1);

    // Reverse the first 'n-k' elements
    reverseArray(arr, 0, n - k - 1);

    // Reverse the entire array
    reverseArray(arr, 0, n - 1);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    // Rotate the array 'arr' by 'k' times
    rotateArray(arr, n, k);

    // Print the rotated array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
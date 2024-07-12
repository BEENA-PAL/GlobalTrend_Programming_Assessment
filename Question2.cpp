// Given a string, find the length of the longest substring without repeating characters.The function should return an integer representing the length of the longest substring without repeating characters.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(const string &s)
    {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int start = 0; // Start of the current window

        for (int end = 0; end < s.size(); ++end)
        {
            if (charIndexMap.find(s[end]) != charIndexMap.end())
            {
                // Move the start position to the right of the duplicate character
                start = max(start, charIndexMap[s[end]] + 1);
            }
            // Update the character's index
            charIndexMap[s[end]] = end;
            // Update the maximum length found
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    string s1 = "abcabcbb";
    cout << "Test case 1: Input: " << s1 << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s1) << endl;

    // Test case 2
    string s2 = "bbbbb";
    cout << "Test case 2: Input: " << s2 << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s2) << endl;

    // Test case 3
    string s3 = "pwwkew";
    cout << "Test case 3: Input: " << s3 << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s3) << endl;

    // Additional test case 4
    string s4 = "";
    cout << "Test case 4: Input: " << s4 << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s4) << endl;

    // Additional test case 5
    string s5 = "abcdef";
    cout << "Test case 5: Input: " << s5 << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s5) << endl;

    return 0;
}

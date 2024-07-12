// Given a non-empty binary tree, find the maximum path sum. A path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.The function should return an integer representing the maximum path sum.

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Helper function to calculate the maximum path sum starting from the current node
    int maxPathSumHelper(TreeNode *root, int &maxSum)
    {
        if (root == nullptr)
        {
            return 0;
        }

        // Recursively calculate maximum path sums for left and right subtrees
        int leftSum = max(0, maxPathSumHelper(root->left, maxSum));
        int rightSum = max(0, maxPathSumHelper(root->right, maxSum));

        // Calculate the maximum path sum that includes the current node
        int maxPathThroughRoot = root->val + leftSum + rightSum;

        // Update the global maximum path sum if the current path is greater
        maxSum = max(maxSum, maxPathThroughRoot);

        // Return the maximum path sum starting from the current node (either left or right subtree)
        return root->val + max(leftSum, rightSum);
    }

    // Function to find the maximum path sum in a binary tree
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN; // Initialize with the minimum integer value
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }
};

// Helper function to create a binary tree from array representation (for testing)
TreeNode *createTreeFromArray(const vector<int> &arr, int index)
{
    TreeNode *root = nullptr;
    if (index < arr.size())
    {
        if (arr[index] == -1)
        {
            return nullptr;
        }
        root = new TreeNode(arr[index]);
        root->left = createTreeFromArray(arr, 2 * index + 1);
        root->right = createTreeFromArray(arr, 2 * index + 2);
    }
    return root;
}

int main()
{
    // Example usage
    vector<int> arr = {1, 2, 3};
    TreeNode *root = createTreeFromArray(arr, 0);

    Solution sol;
    cout << "Maximum path sum: " << sol.maxPathSum(root) << endl;

    return 0;
}

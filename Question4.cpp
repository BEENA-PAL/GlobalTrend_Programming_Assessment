// Design an algorithm to serialize and deserialize a binary tree. Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment. Implement the serialize and deserialize methods.
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    void levelOrder(TreeNode *root, string &s)
    {
        if (root == NULL)
        {
            return;
        }
        queue<TreeNode *> q;
        q.push(root);
        s.append(to_string(root->val));
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front->left)
            {
                q.push(front->left);
                s.push_back(',');
                s.append(to_string(front->left->val));
            }
            else
            {
                s.push_back(',');
                s.push_back('#');
            }
            if (front->right)
            {
                q.push(front->right);
                s.push_back(',');
                s.append(to_string(front->right->val));
            }
            else
            {
                s.push_back(',');
                s.push_back('#');
            }
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        levelOrder(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
        {
            return NULL;
        }
        string s1 = "";
        int i = 0;
        int n = data.length();
        while (i < n && data[i] != ',')
        {
            s1.push_back(data[i]);
            i++;
        }
        i++;
        int x = stoi(s1);
        TreeNode *root = new TreeNode(x);
        s1.clear();
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            while (i < n && data[i] != ',')
            {
                s1.push_back(data[i]);
                i++;
            }
            i++;
            if (s1 == "#")
            {
                front->left = NULL;
            }
            else
            {
                int val = stoi(s1);
                TreeNode *left = new TreeNode(val);
                front->left = left;
                q.push(left);
            }
            s1.clear();
            while (i < n && data[i] != ',')
            {
                s1.push_back(data[i]);
                i++;
            }
            i++;
            if (s1 == "#")
            {
                front->right = NULL;
            }
            else
            {
                int val = stoi(s1);
                TreeNode *right = new TreeNode(val);
                front->right = right;
                q.push(right);
            }
            s1.clear();
        }
        return root;
    }
};

// Function to print the tree in preorder for verification
void printTree(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
    else
    {
        cout << "# ";
    }
}

int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Initialize the codec object
    Codec codec;

    // Serialize the binary tree
    string serializedString = codec.serialize(root);
    cout << "Serialized tree: " << serializedString << endl;

    // Deserialize the string back into a tree
    TreeNode *deserializedTree = codec.deserialize(serializedString);

    // Print the deserialized tree for verification
    cout << "Deserialized tree (preorder traversal): ";
    printTree(deserializedTree);
    cout << endl;

    return 0;
}

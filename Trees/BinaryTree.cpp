#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;

    TreeNode(int x)
    {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
};

class Tree
{
public:
    TreeNode *root;

    Tree()
    {
        root = nullptr;
    }
};

TreeNode *insert(int x, TreeNode *root, TreeNode *parent)
{
    if (root == nullptr)
    {
        TreeNode *temp = new TreeNode(x);
        temp->parent = parent;
        root = temp;
    }
    else
    {
        if (root->val >= x)
        {
            root->left = insert(x, root->left, root);
        }
        else
        {
            root->right = insert(x, root->right, root);
        }
    }
    return root;
}

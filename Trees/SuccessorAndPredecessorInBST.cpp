#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node *left;
    node *right;

    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Tree
{

public:
    node *root;
    Tree()
    {
        this->root = nullptr;
    }
    node *insert(node *root, int val);
    void getSuccessorAndPredecessor(node *root, node *&pre, node *&suc, int val);
};

node *Tree::insert(node *root, int val)
{
    if (root == nullptr)
    {
        node *temp = new node(val);
        root = temp;
    }
    else
    {
        if (root->val >= val)
            root->left = insert(root->left, val);
        else
        {
            root->right = insert(root->right, val);
        }
    }
    return root;
}

void Tree::getSuccessorAndPredecessor(node *root, node *&pre, node *&suc, int val)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->val == val)
    {
        if (root->left)
        {
            node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }

        if (root->right)
        {
            node *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            suc = temp;
        }
    }

    if (root->val > val)
    {
        suc = root;
        getSuccessorAndPredecessor(root->left, pre, suc, val);
    }
    else
    {
        pre = root;
        getSuccessorAndPredecessor(root->right, pre, suc, val);
    }
}

int main()
{
    int key = 65;
    Tree tr;

    tr.root = tr.insert(tr.root, 50);
    tr.root = tr.insert(tr.root, 30);
    tr.root = tr.insert(tr.root, 20);
    tr.root = tr.insert(tr.root, 40);
    tr.root = tr.insert(tr.root, 70);
    tr.root = tr.insert(tr.root, 60);
    tr.root = tr.insert(tr.root, 80);

    node *pre = NULL, *suc = NULL;

    tr.getSuccessorAndPredecessor(tr.root, pre, suc, key);

    if (pre)
        cout << "\nPredecessor: " << pre->val;
    else
    {
        cout << "\nNo Predecessor!!";
    }
    if (suc)
        cout << "\nSuccessor: " << suc->val;
    else
    {
        cout << "\nNo Successor!!";
    }
}

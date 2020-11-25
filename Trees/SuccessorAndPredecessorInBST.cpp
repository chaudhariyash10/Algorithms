#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
};

class Tree
{
    node *root;
    pair<int, int> helper(node *root, int val, node *suc, node *pre);

public:
    Tree();
    void insert(int val);
    int getSuccessorAndPredecessor(int val);
};



int main()
{
}
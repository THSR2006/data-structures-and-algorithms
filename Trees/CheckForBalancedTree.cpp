#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int data=0)
    {
        this->data = data;
    }
};

int isBalanced(Node* root)
{
    if(root==nullptr)
        return 0;

    int lh = isBalanced(root->left);

    if(lh==-1)
        return -1;

    int rh = isBalanced(root->right);

    if(rh==-1)
        return -1;

    if(abs(lh-rh)>1)
        return -1;
    else
        return max(lh, rh) + 1;
}

int main()
{
    Node* root = new Node(20);
    root->right = new Node(8);
    root->right->left = new Node(3);
    root->right->right = new Node(9);

    cout<<isBalanced(root);
    return 0;
}
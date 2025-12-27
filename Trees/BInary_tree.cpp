#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data=0, Node* left=NULL, Node* right=NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

int main()
{   
            /* tree -       10
                        15      5
                    20     25       30 */

    Node* root = new Node(10);         
    Node* N1 = new Node(5);       
    Node* N2 = new Node(15);
    Node* N3 = new Node(20);
    Node* N4 = new Node(25);
    Node* N5 = new Node(30);

    root->right = N1;
    root->left = N2;
    root->left->left = N3;
    root->left->right = N4;
    root->right->right = N5;

    return 0;
}
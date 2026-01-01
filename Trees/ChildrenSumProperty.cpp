#include <iostream>
#include <vector>
#include <queue>

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

Node* constructBinaryTree(const vector<int>& arr)
{
    const int len = arr.size();

    if(arr.empty() || len>1024)
        return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i=1;

    while(i<len)
    {
        Node* current = q.front();
        q.pop();

        if(i<len)
        {
            current->left = new Node(arr[i++]);
            q.push(current->left);
        }

        if(i<len)
        {
            current->right = new Node(arr[i++]);
            q.push(current->right);
        }
    }

    return root;
}

bool checkChildrenSumProp(Node* root)
{
    if(root==nullptr)
        return true;

    if(root->left==nullptr && root->right==nullptr)
        return true;

    int sum = 0;

    if(root->left!=nullptr)
        sum += root->left->data;

    if(root->right!=nullptr)
        sum += root->right->data;

    return root->data == sum && checkChildrenSumProp(root->left) && checkChildrenSumProp(root->right);
}

int main()
{
    vector<int> v = {20, 12, 8, 3, 9};

    Node* root = constructBinaryTree(v);
    cout<<checkChildrenSumProp(root);
}
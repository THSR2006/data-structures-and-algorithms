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

void preorderTraversal(Node* root)
{   
    if(root==nullptr)
        return;
    
    cout<<root->data<<',';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

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

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    Node* root = constructBinaryTree(v);
    preorderTraversal(root);
    return 0;
}
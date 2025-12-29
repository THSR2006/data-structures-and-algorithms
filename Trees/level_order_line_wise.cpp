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

void levelorder_line_wise(Node* root)
{
    if(root==nullptr)
        return;

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(q.size()>1)
    {
        Node* current = q.front();
        q.pop();

        if(current != nullptr)
        {
            cout<<current->data<<',';

            if(current->left!=nullptr)
                q.push(current->left);

            if(current->right!=nullptr)
                q.push(current->right);
        }
        else
        {
            cout<<endl;
            q.push(nullptr);
        }
    }
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    Node* root = constructBinaryTree(v);
    levelorder_line_wise(root);
    return 0;
}
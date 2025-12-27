#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x = 0)
    {
        data = x;
        next = nullptr;
    }
};

void display(Node* N)
{
    while (N != NULL)
    {
        cout << N->data;

        if (N->next != NULL)
            cout << " -> ";

        N = N->next;
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter length of the Singly linked list (1 <= length <= 100): ";
    cin >> n;

    if (n > 0 && n <= 100)
    {
        int x;
        cout << "\nEnter element-1: ";
        cin >> x;

        Node* head = new Node(x);
        Node* prev = head;

        for (int i = 2; i <= n; i++)
        {
            cout << "\nEnter element-" << i << ": ";
            cin >> x;
            
            Node* curr = new Node(x);
            prev->next = curr;
            prev = curr;
        }

        display(head);

        Node* temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    else
    {
        cout << "Invalid length entered!" << endl;
    }

    return 0;
}
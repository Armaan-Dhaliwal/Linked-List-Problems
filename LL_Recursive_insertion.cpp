// Insert Element at ith position of a Linked List using Recursion
#include <iostream>
#include "Node_Class.cpp"
using namespace std;

Node *Insert_Elements()
{

    Node *head = NULL;
    Node *tail = NULL;

    int data;
    cout << "Enter your element" << endl;
    cin >> data;

    while (data != -1)
    {

        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }

    return head;
}

Node *Insert_at_ith_Rec(Node *head, int data, int pos)
{

    if (head == NULL)
    {
        return head;
    }

    if (pos == 1)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    head->next = Insert_at_ith_Rec(head->next, data, pos - 1);
    return head;
}

void print(Node *head)
{
    Node *temp = head;

    cout << "Elements are:" << endl;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node *head = Insert_Elements();
    print(head);

    int data;
    cout << "Enter your data: " << endl;
    cin >> data;

    int pos;
    cout << "Enter the position at which you want to enter the element: " << endl;
    cin >> pos;

    head = Insert_at_ith_Rec(head, data, pos);
    print(head);
}
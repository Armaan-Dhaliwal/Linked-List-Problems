// Delete ith Node of a Linked List using Recursion
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

Node *Delete_ith_Rec(Node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }

    if (pos == 1)
    {
        head = head->next;
        return head;
    }

    head->next = Delete_ith_Rec(head->next, pos - 1);
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

    int pos;
    cout << "Enter the position from which you want to delete the element: " << endl;
    cin >> pos;

    head = Delete_ith_Rec(head, pos);
    print(head);
}
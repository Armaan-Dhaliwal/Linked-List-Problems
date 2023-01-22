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

int Length_Rec(Node *head)
{
    Node *temp = head;

    if (temp == NULL)
    {

        return 0;
    }

    return 1 + Length_Rec(temp->next);
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
    int len = Length_Rec(head);
    cout << "Length of the list is: " << len << endl;
}
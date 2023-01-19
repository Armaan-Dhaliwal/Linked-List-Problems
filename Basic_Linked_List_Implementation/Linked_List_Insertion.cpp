#include <iostream>
#include "Node_Class.cpp"
using namespace std;

Node *Insert_Elements()
{

    char choice = 'y';

    Node *head = NULL;
    Node *tail = NULL;

    while (choice == 'y')
    {
        int data;
        cout << "Enter your element" << endl;
        cin >> data;

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
        cout << "Press y to enter another element and n to exit" << endl;
        cin >> choice;
    }

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
}

int main()
{

    Node *head = Insert_Elements();
    print(head);
}
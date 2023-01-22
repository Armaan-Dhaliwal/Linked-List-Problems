// Insert Elememt at ith Position
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

Node *Insert_ith(Node *head, int pos, int data)
{
    Node *newNode = new Node(data);
    int count = 0;

    Node *temp = head;

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    while (temp->next != NULL && count != pos - 2)
    {
        count++;
        temp = temp->next;
    }

    if (temp->next != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }

    cout << "Overlimit!" << endl;
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

    head = Insert_ith(head, pos, data);
    print(head);
}
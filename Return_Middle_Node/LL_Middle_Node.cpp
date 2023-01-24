#include <iostream>
#include "Node_Class.cpp"
#include <math.h>
using namespace std;

Node *Insert_Elements()
{

    Node *head = NULL;
    Node *tail = NULL;

    int data;
    cout << "Enter your elements: " << endl;
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

int Length(Node *head)
{
    int count = 0;

    if (head == NULL)
    {
        return 0;
    }

    while (head->next != NULL)
    {
        count++;
        head = head->next;
    }
    count++;
    return count;
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

Node *Return_Middle(Node *head)
{
    int len = Length(head);
    Node *temp = head;
    if (len % 2 == 0)
    {
        int count = 1;
        while (count != len / 2)
        {
            head = head->next;
            count++;
        }

        return head;
    }

    head = temp;
    if (len % 2 != 0)
    {
        int count = 0;
        while (count != len / 2)
        {
            head = head->next;
            count++;
        }

        return head;
    }

    return head;
}

int main()
{

    int t;
    cout << "Enter number of test cases: " << endl;
    cin >> t;
    while (t > 0)
    {
        t--;
        Node *head = Insert_Elements();
        print(head);
        int len = Length(head);

        if (len != 0)
        {
            Node *Middle_Node = Return_Middle(head);
            cout << "middle node is: " << Middle_Node->data << endl;
        }

        else
            continue;
    }
}
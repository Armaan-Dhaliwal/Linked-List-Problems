#include <iostream>
#include "Node_Class.cpp"
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

    while (head->next != NULL)
    {
        count++;
        head = head->next;
    }
    count++;
    return count;
}

Node *Move_Elements(Node *head, int num)
{

    int len = Length(head);
    Node *temp = head;
    int rem = len - num;

    while (head->next != NULL)
    {
        head = head->next;
    }

    head->next = temp;

    for (int i = 0; i < rem - 1; i++)
    {
        temp = temp->next;
    }
    Node *newHead = temp->next;
    temp->next = NULL;

    return newHead;
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

    int t;
    cout << "Enter number of test cases: " << endl;
    cin >> t;
    while (t > 0)
    {
        t--;
        Node *head = Insert_Elements();
        print(head);

        int num;
        cout << "Enter the number of elemnets you want to from end to front: " << endl;
        cin >> num;

        head = Move_Elements(head, num);
        print(head);
    }
}
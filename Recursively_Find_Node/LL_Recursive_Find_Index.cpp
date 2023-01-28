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

int Recursive_index(Node *head, int val)
{

    if (head->data == val)
    {
        return 0;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == val)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp->next == NULL && temp->data != val)
    {
        return -1;
    }

    if (head->next != NULL)
    {
        return 1 + Recursive_index(head->next, val);
    }

    return -1;
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

        int val;
        cout << "Enter the value you want to search: " << endl;
        cin >> val;

        int index = Recursive_index(head, val);
        cout << "Index is: " << index << endl;
    }
}
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

bool Check_Palindrome(Node *head, Node *tail, int length)
{

    if (length <= 1)
    {

        return true;
    }

    if (length > 1)
    {

        if (head->data == tail->data)
        {

            int len = length;
            Node *tail = head;
            while (len - 2 > 0)
            {
                tail = tail->next;
                len--;
            }
            return Check_Palindrome(head->next, tail, length - 2);
        }

        else
            return false;
    }

    return false;
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
        float len = Length(head);

        Node *tail = head;

        if (len > 0)
        {
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
        }

        if (Check_Palindrome(head, tail, ceil(len)) || len == 0)
        {
            cout << "True" << endl;
        }

        else if (!Check_Palindrome(head, tail, ceil(len)))
        {
            cout << "False" << endl;
        }
    }
}
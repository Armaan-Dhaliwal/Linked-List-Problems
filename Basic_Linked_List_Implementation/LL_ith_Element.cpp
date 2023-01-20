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

int ith_element(Node *head, int pos)
{
    int count = 1;
    if (count == pos)
    {
        return head->data;
    }

    else
    {
        while (count != pos)
        {
            count++;
            head = head->next;
        }

        return head->data;
    }
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

    int t, pos;
    cout << "Enter number of test cases: " << endl;
    cin >> t;

    while (t > 0)
    {
        Node *head = Insert_Elements();
        print(head);
        cout << "\nEnter the position of element you want: " << endl;
        cin >> pos;
        int ele = ith_element(head, pos);
        cout << ele << endl;
        t--;
    }
}
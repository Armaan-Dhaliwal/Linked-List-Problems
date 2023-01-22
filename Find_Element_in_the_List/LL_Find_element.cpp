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

int Find_element(Node *head, int data)
{

    int count = 0;

    while (head->data != data && head->next != NULL)
    {
        head = head->next;
        count++;
    }

    if (head->next != NULL)
    {
        return count;
    }

    else
    {
        cout << "Element isn't there in the list" << endl;
        return -1;
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

        int data;
        cout << "Enter the Element you want to Serach in Linked List: " << endl;
        cin >> data;

        int index = Find_element(head, data);
        cout << "Index of required element is : " << index << endl;
    }
}
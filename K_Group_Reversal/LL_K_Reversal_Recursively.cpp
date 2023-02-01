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

Node *Reverse_K(Node *head, int k)
{
    int K = k;
    Node *head_check = head;
    Node *tail;
    Node *temp;
    Node *prev;

    if (K <= 1)
    {
        return head;
    }

    while (K > 1 && head_check != NULL)
    {
        head_check = head_check->next;
        K--;
    }

    if (head_check == NULL)
    {
        return head;
    }

    if (head_check != NULL)
    {
        head_check = head_check->next;
        K = k;
        prev = NULL;
        temp = head;
        Node *Next;

        while (K > 0 && head != NULL)
        {
            K--;
            Next = head->next;
            head->next = prev;
            prev = head;
            head = Next;
        }

        temp = prev;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        tail = temp;
        tail->next = Reverse_K(head_check, k);
    }

    return prev;
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

        int k;
        cout << "Enter K: " << endl;
        cin >> k;

        head = Reverse_K(head, k);
        print(head);
    }
}
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

Node *Odd_to_Even(Node *head)
{
    Node *Even_head = NULL;
    Node *Odd_head = NULL;
    Node *temp = head;

    if (head->data % 2 == 0)
    {
        Even_head = head;
        head = head->next;
        Even_head->next = NULL;
    }

    else if (head->data % 2 != 0)
    {
        Odd_head = head;
        head = head->next;
        Odd_head->next = NULL;
    }

    cout << "Initially Even_head is: " << endl;
    print(Even_head);
    cout << "Initially Odd_head is: " << endl;
    print(Odd_head);

    Node *Even_temp = Even_head;
    Node *Odd_temp = Odd_head;

    while (head != NULL)
    {

        cout << "head is at: " << head->data << endl;
        if (head->data % 2 == 0)
        {
            if (Even_head != NULL)
            {
                Even_head->next = head;
                cout << head->data << " is done 2 " << endl;
                head = head->next;
                Even_head = Even_head->next;
                continue;
            }

            else if (Even_head == NULL)
            {
                Even_head = head;
                head = head->next;
                Even_temp = Even_head;
                cout << head->data << " is done 1 " << endl;
                cout << "head is: " << endl;

                continue;
                print(head);
            }
        }

        if (head->data % 2 != 0)
        {

            if (Odd_head != NULL)
            {
                cout << head->data << " is done 4" << endl;
                Odd_head->next = head;
                head = head->next;
                Odd_head = Odd_head->next;
                continue;
            }

            else if (Odd_head == NULL)
            {
                Odd_head = head;
                head = head->next;
                Odd_temp = Odd_head;
                cout << head->data << " is done 3 " << endl;
                continue;
            }
        }

        temp = temp->next;
        cout << head->data << " is called " << endl;
    }

    if (Even_head == NULL)
    {
        Odd_head = Odd_temp;
        return Odd_head;
    }

    if (Odd_head == NULL)
    {
        Even_head->next = NULL;
        return Even_temp;
    }

    Odd_head->next = Even_temp;
    Odd_head = Odd_temp;
    Even_head->next = NULL;

    return Odd_head;
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

        Node *newHead = Odd_to_Even(head);
        print(head);
    }
}
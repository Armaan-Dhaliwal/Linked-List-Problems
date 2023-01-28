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

Node *Merge(Node *head1, Node *head2)
{
    Node *headNew;
    if (head1->data <= head2->data)
    {
        headNew = head1;
        head1 = head1->next;
    }

    else if (head1->data > head2->data)
    {
        headNew = head2;
        head2 = head2->next;
    }

    Node *temp = headNew;

    while (head1 != NULL || head2 != NULL)
    {

        if (head1 != NULL && head2 != NULL)
        {
            if (head1->data <= head2->data)
            {
                headNew->next = head1;
                head1 = head1->next;
                headNew = headNew->next;
            }

            else if (head1->data > head2->data)
            {
                headNew->next = head2;
                head2 = head2->next;
                headNew = headNew->next;
            }
        }

        if (head1 != NULL && head2 == NULL)
        {
            while (head1 != NULL)
            {
                headNew->next = head1;
                head1 = head1->next;
                headNew = headNew->next;
            }
        }

        if (head1 == NULL && head2 != NULL)
        {
            while (head2 != NULL)
            {
                headNew->next = head2;
                head2 = head2->next;
                headNew = headNew->next;
            }
        }
    }
    headNew->next = NULL;
    headNew = temp;

    return headNew;
}

Node *Merge_Sort(Node *head)
{

    Node *newHead;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = Return_Middle(head);
    Node *midTemp = mid->next;
    mid->next = NULL;

    Node *newHead1 = Merge_Sort(head);
    Node *newHead2 = Merge_Sort(midTemp);

    newHead = Merge(newHead1, newHead2);

    return newHead;
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

        head = Merge_Sort(head);
        cout << "After Merge Sort: " << endl;
        print(head);
    }
}
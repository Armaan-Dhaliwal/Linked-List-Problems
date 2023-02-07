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

Node *Bubble_Sort(Node *head)
{
    Node *temp = head;
    Node *newHead = NULL;
    Node *prev = NULL;

    Node *Next;

    while (temp != NULL)
    {

        int count = 0;
        while (temp->next != NULL)
        {
            if (temp->data > (temp->next)->data)
            {
                Next = temp->next;
                temp->next = Next->next;
                Next->next = temp;
                count++;

                if (count == 1 && Next->next == head)
                {
                    newHead = Next;
                    prev = newHead;
                }

                else if (count == 1 && Next->next != head)
                {
                    prev->next = Next;
                    prev = prev->next;
                }

                else
                {
                    prev->next = Next;
                    prev = prev->next;
                }
            }

            else if (temp->data <= (temp->next)->data)
            {
                prev = temp;
                temp = temp->next;
                cout << " In 2nd :" << endl;
            }
        }

        if (newHead != NULL)
        {
            head = newHead;
        }

        temp = head;

        while (temp->next != NULL && temp->data < temp->next->data)
        {
            temp = temp->next;
        }

        if (temp->next != NULL)
        {
            temp = head;
        }

        else
            temp = NULL;
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

        head = Bubble_Sort(head);
        cout << "Sorted Elements: " << endl;
        print(head);
    }
}

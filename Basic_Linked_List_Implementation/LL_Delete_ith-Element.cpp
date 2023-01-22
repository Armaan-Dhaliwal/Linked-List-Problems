#include <iostream>
#include "Node_Class.cpp"
using namespace std;

Node *Insert_Elements()
{

    Node *head = NULL;
    Node *tail = NULL;

    int data;
    cout << "Enter your element" << endl;
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

Node *Delete_ith(Node *head, int pos)
{
    if (pos == 1)
    {
        head = head->next;
        return head;
    }

    int count = 0;
    Node *temp = head;
    while (temp->next != NULL && count != pos - 2)
    {
        count++;
        temp = temp->next;
    }

    if (temp->next != NULL)
    {
        Node *temp1 = temp->next;
        temp->next = temp1->next;
        return head;
    }

    cout << "  Overlimit !!" << endl;
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

int main()
{

    Node *head = Insert_Elements();
    print(head);

    int pos;
    cout << "Enter the position from which you want to delete the element: " << endl;
    cin >> pos;
    head = Delete_ith(head, pos);
    print(head);
}
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

void Delete_N_after_M(Node *head, int N, int M)
{
    Node *temp = head;
    int Ntemp = N;
    int Mtemp = M;

    while (temp != NULL)
    {
        M = Mtemp;
        N = Ntemp;
        while (M > 1 && temp != NULL)
        {
            temp = temp->next;
            M--;
        }

        Node *holder = temp;
        temp = temp->next;

        while (N > 0 && temp != NULL)
        {
            Node *del = temp;
            temp = temp->next;
            delete del;
            N--;
            holder->next = temp;
        }
    }

    return;
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

        int N, M;
        cout << "Enter N: " << endl;
        cin >> N;
        cout << "Enter M: " << endl;
        cin >> M;
        Delete_N_after_M(head, N, M);
        print(head);
    }
}
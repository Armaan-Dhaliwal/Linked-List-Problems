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

Node* Swap_Nodes(Node* head, int i , int j){

    int iTemp = i;
    int jTemp = j;
    Node* temp1 = head;
    Node* temp2 = head;
    Node* prev1;
    Node* next1;

    if (i == 1 && j>=2)
    {
    cout<<"Entered in 1st "<<endl;

    while (j>2)
    {   
        j--;
        temp2 = temp2->next;
    }
    Node* prev2 = temp2;
    temp2 = temp2->next;

     i = iTemp;
    j = jTemp;
    if ((j-i) == 1)
    {   
        cout<<"reached in j-i"<<endl;
        head = temp2;
        Node* next2 = temp2->next;
        temp2->next= temp1;  
        temp1->next = next2;
        return head;
          
    }

    head = temp2;
    next1 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = next1;// temp1->next
    prev2->next = temp1;
    return head;
    }

    if(i>=2 && j>=2){


    cout<<"Entered in 2nd "<<endl;

    while (i>2)
    {   
        i--;
        temp1 = temp1->next;
    }
    Node* prev1 = temp1;
    temp1 = temp1->next;

    while (j>2)
    {   
        j--;
        temp2 = temp2->next;
    }
    Node* prev2 = temp2;
    temp2 = temp2->next;
    //cout<<"Ready to enter j-i "<<endl;

    i = iTemp;
    j = jTemp;
    if ((j-i) == 1)
    {   
        cout<<"reached in j-i"<<endl;
        prev1->next = temp2;
        Node* next2 = temp2->next;
        temp2->next= temp1;  
        temp1->next = next2;
        return head;
          
    }
        
    cout<<"Entering area not allowed: "<<endl;
    prev1->next = temp2;
    next1 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = next1;
    prev2->next = temp1;
    return head;
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

        cout<<"In order to swap ith and jth Node: "<<endl;
        int i, j;
        cout << "Enter i: " << endl;
        cin >> i;
        cout << "Enter j: " << endl;
        cin >> j;
        head = Swap_Nodes(head, i, j);
        print(head);
    }
}
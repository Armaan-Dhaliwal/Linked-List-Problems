#include<iostream>
#include<stack>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    { 
        this->data = data;
        next = NULL;
    }
};

int carry=0;
LinkedListNode<int>* Recursive_add(LinkedListNode<int> *head){

    if((head->next)->data==-1){
      if (head->data == 9) {
        head->data = 0;
        carry=1;
        return head;
      }
      else{
          head->data+=1;
          carry=0;
          return head;
      }
    }
        head->next=Recursive_add(head->next);
        if(carry==1 ){
            if(head->data==9){
                head->data=0;
                carry=1;
            }
            else{
                head->data+=1;
                carry=0;
            }
        }
    return head;
}     

LinkedListNode<int>* addOneToList(LinkedListNode<int> *head)
{   
    LinkedListNode<int> *new_head=Recursive_add(head);
    if(new_head->data==0){
         LinkedListNode<int>* new_Node=new LinkedListNode<int>(1);
         new_Node->next=new_head;
         new_head=new_Node;

    }
    return new_head;
}



int main(){
    LinkedListNode<int>* head= new  LinkedListNode<int>(9) ;
    int n;
    cin>>n;
        LinkedListNode<int>* temp=new  LinkedListNode<int>(0);
        head->next=temp;
        LinkedListNode<int>* emp_new=new LinkedListNode<int>(0);
        temp->next=emp_new;
        LinkedListNode<int>* emp_new1=new LinkedListNode<int>(-1);
        emp_new->next=emp_new1;

    LinkedListNode<int>* new_head = addOneToList(head);
    while(new_head->next!=NULL){
        cout<<new_head->data<<" ";
        new_head=new_head->next;
    }
}
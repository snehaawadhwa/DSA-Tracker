#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

//insert a new node in front
//of the list
void pushHere(node** head, int val){

    node* new_node= new node();
    new_node->data=val;
    new_node->next=*head;
    *head=new_node;
}

//insert a new node after
//given previous node
void insertHere(node* prev, int val){

    if(prev==NULL){
        cout<<"can't be null";
        return;
    }

    node* new_node= new node();
    new_node->data=val;
    new_node->next=prev->next;
    prev->next=new_node;
}

//insert a new node at the
//end of the list
void appendHere(node** head, int val){
    node* new_node= new node();
    node* last= *head;
    new_node->data=val;
    new_node->next=NULL;

    if(*head==NULL){
        *head=new_node;
        return;
    }

    while(last->next!=NULL){
        last=last->next;
    }
    last->next=new_node;
    return;
}

//remove last from list
node* removeLast(node* head){
    if(head==NULL){
        return NULL;
    }

    if(head->next=NULL){
        delete(head);
        return NULL;
    }

    node* sec_last=head;
    while(sec_last->next->next!=NULL){
        sec_last=sec_last->next;
    }
    delete(sec_last->next);

    sec_last->next=NULL;

    return head;
}


//print function that prints
//the entire list
void printList(node* node){
    while(node!=NULL){
        cout<<" "<<node->data;
        node=node->next;
    }
}

//driver code
int main()
{   // Start with the empty list
    node* head = NULL;
     
    // Insert 6. So linked list becomes 6->NULL
    appendHere(&head, 6);
     
    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    pushHere(&head, 7);
     
    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    pushHere(&head, 1);
     
    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    appendHere(&head, 4);
     
    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertHere(head->next, 8);
     
    cout<<"Created Linked list is: ";
    printList(head);

    head= removeLast(head);
    cout<<"Created Linked list is: ";
    printList(head);
     
    return 0;
}

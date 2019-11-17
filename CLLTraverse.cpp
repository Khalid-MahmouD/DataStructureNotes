#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
//O(N)
void push(Node **headRef, int data){
    Node *temp = new Node();
    Node *cur = (*headRef);
    temp -> data = data;
    temp -> next = *headRef;
    // there is itmes befor.
    if(*headRef != NULL){
        while(cur -> next != (*headRef)) cur = cur ->next;
        cur -> next = temp;
    }
    else temp->next = temp;

    *headRef = temp;
}
// O(N)
void append(Node** headRef, int data){
    Node *cur = (*headRef);
    Node *new_node = new Node();
    new_node -> data = data;

    if(*headRef != NULL){
        while(cur -> next != *headRef)cur = cur -> next;
        cur -> next = new_node;
        new_node -> next = *headRef;
    }
    else
        new_node -> next = new_node;
    *headRef = new_node -> next;
}
void printList(Node*head){
    Node* temp = head;
    if(!head)return ;
    do
    {
        cout << temp -> data <<" ";
        temp = temp-> next;
    }
    while(temp != head);
}
int main(){
    Node* head = NULL;
    append(&head, 12);  
    append(&head, 56);  
    append(&head, 2);  
    append(&head, 11);    
    printList(head);
    return 0;
}
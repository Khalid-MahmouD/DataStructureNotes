#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
};
void push(Node**head, int data){
    Node* new_node = new Node();
    Node* temp = *head;
    new_node -> data = data;
    new_node -> prev = NULL;
    new_node -> next = (*head);
    if((*head) != NULL) (*head)-> prev  = new_node;
    (*head) = new_node;
}
void reverse(Node**head){
    Node*temp=NULL;
    Node*cur = *head;
    while(cur != NULL){
        temp = cur -> prev;
        cur -> prev = cur -> next;
        cur -> next = temp;
        cur = cur -> prev;
    }
    if( (temp) != NULL )(*head) = temp -> prev; 
}
void printList(Node*head){
    while(head!=NULL){
        cout << head->data <<" ";
        head = head -> next;
    }
    cout <<"\n";
}
int main(){
    Node* head =NULL;
    push(&head,2);
    push(&head,2);
    push(&head,2);
    push(&head,3);
    push(&head,3);
    push(&head,3);
    printList(head);
    reverse(&head);
    printList(head);
    return 0;
}
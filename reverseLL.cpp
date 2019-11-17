#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node*next;
};
void push(Node**head,int data){
    Node* new_node = new Node();
    new_node-> data = data;
    if(head != NULL)
    new_node-> next = (*head);
    *head = new_node;
}
//https://www.geeksforgeeks.org/reverse-a-linked-list/
void reverse (Node**head){
    Node*next =NULL,*prev=NULL;
    Node*cur = (*head);// 1 -> 2 -> 3
    while(cur != NULL){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next; 
    }
    *head = prev;
}
void printList(Node*n){
    while(n != NULL){
        cout << n -> data <<" ";
        n = n -> next;
    }
    cout <<"\n";
}
int main(){
    Node*head =NULL;
    push(&head,1);
    push(&head,1);
    push(&head,1);
    push(&head,3);
    push(&head,3);
    push(&head,3);
    printList(head);
    reverse(&head);
    printList(head);
    return 0;
}
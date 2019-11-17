#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};
void splitList(Node* head, Node**head1, Node**head2){
    Node* slow = head, *fast = head;
    if(!head)return;
    while(fast->next->next !=head && fast -> next !=head){
        fast = fast->next->next;
        slow = slow -> next;
    }
    //even number of nodes?
    if(fast->next->next == head)fast = fast -> next;
    
    *head1 = head;   
    
    if(head -> next != head) *head2 = slow -> next;

    fast -> next = slow -> next;

    slow -> next = head;

}
void push(Node**head, int data){
    Node* new_node = new Node();
    Node* temp = (*head);
    new_node -> data = data;
    new_node -> next = *head;
    if(*head != NULL){
    while(temp -> next != *head)temp = temp -> next;
    temp -> next = new_node;
    }
    else new_node -> next = new_node;

    *head = new_node;
}

void append(Node**head, int data){
    Node* new_node = new Node();
    Node* temp = *head;
    new_node -> data = data;
    if(!head){
        while(temp -> next != *head)temp = temp -> next;
        new_node -> next = temp;
        temp -> next = *head;
    }
    else new_node -> next = new_node;

    *head = temp;
}
void printList(Node*head){
    Node* temp = head;
    if(head){
            cout << "\n";
        do{
            cout << temp -> data <<" ";
            temp = temp -> next;
        }
        while(temp  != head);
    }
}
int main(){
Node* head =NULL;
Node* head1 =NULL;
Node* head2 = NULL;

/* Created linked list will be 12->56->2->11 */
    push(&head, 12);  
    push(&head, 56);  
    push(&head, 2);  
    push(&head, 11); 
    cout << "Original Circular Linked List";      
    printList(head);
    splitList(head,&head1,&head2);
    cout << "\nFirst Circular Linked List"; 
    printList(head1);
    cout << "\nSecond Circular Linked List";  
    printList(head2);

    return 0;
}
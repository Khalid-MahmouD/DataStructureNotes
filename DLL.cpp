#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node*next;
    Node*prev;
};
// 5 steps.
void push(Node**head, int data){
    Node* new_node = new Node();
    new_node -> data = data;
    //Make next of new node as head and previous as NULL
    new_node -> next = *head;
    new_node -> prev = NULL;
    //change prev of head node to new node
    if((*head)!=NULL)
        (*head) -> prev = new_node; 
    //head to new node
    *head = new_node;
}
// 7 steps.
void append(Node**head,int data){
    Node* new_node = new Node();
    Node* last = *head;
    new_node -> data = data;
    new_node -> next =NULL;
    //empty
    if(*head == NULL){
        new_node -> prev = last;
        (*head) = new_node;
        return;
    }
    while(last-> next != NULL)last = last ->next;
    last -> next = new_node;
    new_node -> prev = last;
    return;
}
// 
void insertAfter(Node**head,Node*prev, int data){
    Node* new_node = new Node();
    new_node -> data = data;    
    new_node -> next = prev -> next;
    prev-> next = new_node;
    new_node -> prev = prev;
    if (new_node->next != NULL)
    new_node -> next ->prev = new_node;
}
void insertBefor(Node**head, Node*next_node, int data){
    Node* new_node = new Node;
    new_node -> data = data;

    new_node -> next = next_node;
    new_node -> prev = next_node -> prev; 
    next_node -> prev = new_node;

    if(next_node -> prev != NULL)
        new_node -> prev -> next = new_node;

    else
        (*head) = new_node;
}
void deleteNode(Node**head, Node* del){
    //empty
    if(!head || !del)return;
    // head that he wanna to delete
    if(*head == del) *head = del -> next;

    if(del-> next != NULL)
            del -> next -> prev = del -> prev;
    if(del -> prev != NULL)
            del -> prev -> next = del -> next;
    free(del);
}
void printList(Node*node){
    Node* last;
    while(node != NULL){
        printf(" %d ", node -> data);
        last = node;
        node = node -> next;
    }
    cout <<"\n";
    while(last != NULL){
        printf(" %d ",last -> data);
        last = last -> prev;
    }
}
int main(){
    Node* start =NULL;
    // 1  4  2  3   
    push(&start,1);
    append(&start,2);
    insertAfter(&start, start-> next, 3);
    insertBefor(&start,start->next,4);
    printList(start);
    cout <<"\n after delete \n";
    deleteNode(&start,start->next);
    printList(start);
    return 0;
}
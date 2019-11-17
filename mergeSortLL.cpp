#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node*next;
};
Node* SortedMerge(Node* a, Node* b); 
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef); 
void MergeSort(Node**headRef){
    Node*head = *headRef;
    Node*a, *b; 
    if(!head || !(head->next)) return;
    FrontBackSplit(head,&a,&b);
    MergeSort(&a);
    MergeSort(&b);
    *headRef = SortedMerge(a,b);
}
Node*SortedMerge(Node*a, Node*b){
    Node*res=NULL;
    if(!a) return b;
    if(!b) return a;
    if(a->data <= b->data){
        res = a;
        res -> next = SortedMerge(a->next, b);
    }
    else{
        res = b;
        res -> next = SortedMerge(a, b-> next);
    }
    return res;
}
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef){
   Node*fast,*slow;
   slow = source;
   fast = source -> next;

    while(fast){
        fast = fast->next;
        if(fast){
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    *frontRef = source;
    *backRef = slow -> next;
    slow -> next = NULL;
}
void printList(Node*n){
    while(n){
        cout << n-> data <<" ";
        n = n-> next;
    }
    cout <<"\n";
}
void push(Node**head,int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> next = *head;
    *head  = newNode; 
}
int main(){
    Node* res = NULL; 
    Node* a = NULL; 
    /* Let us create a unsorted linked lists to test the functions  
Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
  
    /* Sort the above created Linked List */
    MergeSort(&a); 
  
    cout << "Sorted Linked List is: \n"; 
    printList(a); 

}
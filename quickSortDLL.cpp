#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node*next;
    Node*prev;
};
void swap ( int* a, int* b ){ int t = *a; *a = *b; *b = t; }
Node *lastNode(Node *root)  
{  
    while (root && root->next)  
        root = root->next;  
    return root;  
}  
Node* partation(Node*l,Node*h){
    int pivot = h-> data;
    Node* i = l->prev;
    for(Node*j = l; j != h ; j = j-> next){
        if(j-> data <= pivot){
            i = (i == NULL) ? l : i->next;
            swap(&(i->data),&(j->data));
        }
    }
    i = (i == NULL) ? l : i->next;
        swap(&(i->data),&(h->data));
        return i;
}
void _quickSort(Node*l,Node*h){
    if (h != NULL && l != h && l != h->next){
        Node*pi = partation(l,h);
        _quickSort(l,pi->prev);
        _quickSort(pi->next,h);
    }
}
void quickSort(Node*head){
    Node*h = lastNode(head);
    _quickSort(head,h);
}
void printList(Node*n){
    while(n){
        cout << n-> data <<" ";
        n = n -> next;
    }
    cout <<"\n";
}
void push(Node**head, int data){
    Node*new_node = new Node();
    new_node->data = data;
    new_node ->prev = NULL;
    new_node -> next = (*head);
    if((*head) != NULL ) (*head) -> prev = new_node;
    (*head) = new_node;
}
int main()  
{  
    Node *a = NULL;  
    push(&a, 5);  
    push(&a, 20);  
    push(&a, 4);  
    push(&a, 3);  
    push(&a, 30);  
  
    cout << "Linked List before sorting \n";  
    printList(a);  
  
    quickSort(a);  
  
    cout << "Linked List after sorting \n";  
    printList(a);  
  
    return 0;  
}

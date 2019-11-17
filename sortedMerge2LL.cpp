#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node*next;
};
void MoveNode (Node**destRef, Node**sourceRef);

Node*SortedMerge(Node*a, Node*b){
    Node dummy;
    Node*tail = &dummy;
    dummy.next = NULL;
    while(1){
        if(a==NULL){tail->next = b; break;}
        else if(b==NULL){tail->next = a; break;}
        
        if(a-> data <= b->data)
            MoveNode(&(tail->next),&a);
        else
            MoveNode(&(tail->next),&b);
        tail = tail -> next;
    }
    return (dummy.next);
}
void MoveNode (Node**destRef, Node**sourceRef){
    Node*new_node = *sourceRef;
        assert(new_node != NULL); 
    // move the source forward; 
    *sourceRef =    new_node -> next;
    // point to null i guess;
    new_node -> next = *destRef;
    //now he did not ;
    *destRef = new_node;
}
void push(Node**head,int data){
    Node*new_node = new Node();
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}
void printList(Node*n){
    while(n){
        cout << n->data <<" ";
        n = n-> next;
    }
    cout<<"\n";
}
int main(){
    Node*a=NULL;
    Node*b=NULL;
    Node*res=NULL;
    push(&a, 15);   
    push(&a, 10);  
    push(&a, 5);  
    push(&b, 20);  
    push(&b, 3);  
    push(&b, 2);
    res = SortedMerge(a,b);
    printList(res);
    return 0;
}
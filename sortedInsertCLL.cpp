#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
};
void sortedInsert(Node**head, Node*new_node){
    Node*temp = *head;
    //empty
    if(*head == NULL) {
        new_node -> next = new_node; 
        *head = new_node;
        }

    //at the begin
    else if(new_node -> data <= temp->data){
        while(temp-> next != *head)
            temp = temp -> next;
        
        temp -> next = new_node;
        new_node -> next = *head;
        *head = new_node; 
    }
    //after head
    else{
        while(temp -> next != *head &&
                temp->next->data <= new_node-> data)
                    temp = temp -> next;
        
        new_node -> next = temp -> next;
        temp -> next = new_node;
    }
}
void printList(Node *start)  
{  
    Node *temp;  
      
    if(start != NULL)  
    {  
        temp = start;  
        do {  
        cout<<temp->data<<" ";  
        temp = temp->next;  
        } while(temp != start);  
    }  
}
int main(){
    int arr[] = {12, 56, 2, 11, 1, 90};  
    int i;
    Node*start = NULL;
    Node*temp ;
    for(i=0;i<6;i++){
        temp = new Node();
        temp-> data = arr[i];
        sortedInsert(&start,temp);
    }
    printList(start);
    return 0;
}
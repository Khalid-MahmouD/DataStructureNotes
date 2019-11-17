#include<bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
struct Node *addToEmpty(struct Node *last, int data) 
{ 
    // This function is only for empty list 
    if (last != NULL) 
      return last; 
  
    // Creating a node dynamically. 
    struct Node *temp =  
           (struct Node*)malloc(sizeof(struct Node)); 
  
    // Assigning the data. 
    temp -> data = data; 
    last = temp; 
  
    // Creating the link. 
    last -> next = last; 
  
    return last; 
} 


struct Node* addBegin(struct Node* last, int data){
    if(!last)return addToEmpty(last,data);
    struct Node* temp =
            (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    return last;
}

struct Node* addEnd(struct Node* last, int data){
    if(!last) return addToEmpty(last,data);
    struct Node *temp =  
            (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
    
    return last;
}
struct Node* addAfter(struct Node* last, int data, int item){
    if (last == NULL)  return NULL; 
    struct Node *p, *temp;
    //head 
    p = last -> next;
    //one cycle
    do
    {
        if(p -> data == item){
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp -> data = data;
            temp -> next = p -> next;
            p -> next = temp;
            if(p == temp)last = temp;
            return last;
        }
        p = p -> next;
    } while(p != last-> next);
    
    return last;
}

void traverse(struct Node* last){
    if (last == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
    struct Node* p = last -> next;
    do
    { 
        cout << p -> data << " "; 
        p = p -> next; 
    } 
    while(p != last->next); 
    cout <<"\n";
}
 
int main(){
    Node* last = NULL;
    // ---> 2 -> 4 -> 6 -> 8 -> 10 -> 12 ---
    last = addToEmpty(last, 6); 
    last = addBegin(last, 4); 
    last = addBegin(last, 2); 
    last = addEnd(last, 8); 
    last = addEnd(last, 12); 
    last = addAfter(last, 10, 8); 
    traverse(last);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class twoStacks{
    int size;
    int top1,top2;
    int *a;
    public:
    twoStacks(int n){
        size = n;
        a = new int[n];
        top1 = -1;
        top2 = size;
    }
    void push1(int x){
        if(top1 < top2 -1)
            a[++top1] = x;
        else {
            cout <<"stackOver"; 
            exit(1);
            }
    }
    void push2(int x){
        if(top1< top2 -1)
            a[--top2] = x;
        else {cout <<"stackOver"; exit(1);}
    }
    int pop1(){
        if(top1 >= 0)return a[top1--];
        else{
            cout << "stack underFlow";
            exit(1);
        }
    }
    int pop2(){
        if(top2 < size) return a[top2++];
        else{
            cout << "stack underFlow";
            exit(1);
        }
    }
};
int main(){
   twoStacks ts(5); 
    ts.push1(5);
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is " << ts.pop1(); 
    ts.push2(40); 
    cout << "\nPopped element from stack2 is " << ts.pop2(); 
    return 0; 
}
/*
push1(int x) –> pushes x to first stack
push2(int x) –> pushes x to second stack

pop1() –> pops an element from first stack and return the popped element
pop2() –> pops an element from second stack and return the popped element
*/
#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
int top;
unsigned cap;
int*array;
};
 Stack* creatStack(unsigned cap){
    Stack*stack = new  Stack();
    if(!stack)return NULL;
    stack->top =-1;
    stack->cap =cap;
    stack->array = new int[stack->cap*sizeof(int)];
    if(!stack->array)return NULL;
    return stack;
}
int isEmpty(Stack* stack)  
{  
    return stack->top == -1 ;  
}  
  
char peek( Stack* stack)  
{  
    return stack->array[stack->top];  
}  
  
char pop( Stack* stack)  
{  
    if (!isEmpty(stack))  
        return stack->array[stack->top--] ;  
    return '$';  
}  
  
void push( Stack* stack, char op)  
{  
    stack->array[++stack->top] = op;  
}
int evalPostfix(char*exp){
     Stack*stack = creatStack(strlen(exp));
    if(!stack)return -1;
    int i;
    for (i = 0; exp[i]; ++i){          
        if(exp[i] == ' ')continue;
        else if(isdigit(exp[i])){
            int num = 0;
            while(isdigit(exp[i])){
                num = num*10 + (int)(exp[i]-'0');
                i++;
            }
            i--;
            push(stack,num);
        }
        else{
            int x = pop(stack);
            int y = pop(stack);
            switch(exp[i]){
                case '+':push(stack,y+x) ;break;
                case '-':push(stack,y-x) ;break;
                case '*':push(stack,y*x) ;break;
                case '/':push(stack,y/x) ;break;
            }
        }   
    }
    return pop(stack);
}
int main(){
    // char exp[] ="231*+9-";
    char exp[] = "100 200 + 2 / 5 * 7 +";  
    cout << evalPostfix(exp);  
    return 0;  
}
/*
Following is algorithm for evaluation postfix expressions.
1) Create a stack to store operands (or values).
2) Scan the given expression and do following for every scanned element.
…..a) If the element is a number, push it into the stack
…..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
3) When the expression is ended, the number in the stack is the final answer

*/
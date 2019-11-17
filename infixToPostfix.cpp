#include<bits/stdc++.h>
using namespace std;
struct Stack{
    int top;
    unsigned cap;
    int*array;
};

struct Stack* creatStack(unsigned cap){
    struct Stack*stack = (struct Stack*)malloc(sizeof(struct Stack));
    if(!stack)return NULL;
    stack -> top = -1;
    stack -> cap = cap;
    stack -> array = (int*)malloc(stack->cap*sizeof(int));
    if(!stack->array) return NULL;
    return stack;
}
int isEmpty(struct Stack*stack){
    return stack-> top == -1;
}
char peek(struct Stack*stack){
    return stack->array[stack->top];
}
char pop(struct Stack*stack){
    if(!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}
void push(struct Stack*stack,char op){
     stack->array[++stack->top] = op;
}
int isOperand(char ch){
    return (ch >='a' && ch <= 'z')|| (ch >= 'A' && ch <='Z');
}
int prec(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;
        
        case '*':
        case '/':
            return 2;
            
        case '^':
            return 3;
    }
    return -1;
}
int infixToPostfix(char*exp){
    int i,k;
    struct Stack*stack = creatStack(strlen(exp));
    if(!stack) return -1;  
    for(i =0,k =-1; exp[i]; ++i){
        if(isOperand(exp[i]))
            exp[++k] = exp[i];
        else if(exp[i] == '(')
            push(stack,exp[i]);
        else if(exp[i] == ')')
        {
            while( !isEmpty(stack) && peek(stack) != '(') 
                exp[++k] = pop(stack);
            if(!isEmpty(stack) && peek(stack) != '(')
                    return -1; // invalid;
            else   
                    pop(stack);
        }
        else{
            while(!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack,exp[i]);
        }
        
    }
    while(!isEmpty(stack))
        exp[++k] = pop(stack);
    exp[++k]='\0';
    printf("%s \n",exp);
}
int main(){
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i"; 
    infixToPostfix(exp);
    return 0; 
}
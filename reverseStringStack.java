import java.util.*; 
class Stack{
    int size;
    int top;
    char[]a;
    boolean isEmpty(){
        return top < 0;
    }
    Stack(int n){
        top = -1;
        size = n;
        a = new char[size];        
    }
    void push(char x){
        if(top >= size){
            System.out.println("Stack overFlow");
            return;
        }
        a[++top] = x;
    }
    char pop(){
        if(top < 0){
            System.out.println("Stack underFlow");
            return 0;
        }
        return (char)a[top--];
    }
};
class reverseStringStack
{
    public static void reverse(StringBuffer str){
        int n = str.length();
        Stack stack = new Stack(n);

        for(int i=0;i<n;++i)
            stack.push(str.charAt(i));
        for(int i=0;i<n;++i)
        {  
            char ch = stack.pop(); 
            str.setCharAt(i,ch); 
        } 

    }
    public static void main(String args[]) 
    { 
        //create a new string 
        StringBuffer s= new StringBuffer("GeeksQuiz"); 
          
        //call reverse method 
        reverse(s); 
          
        //print the reversed string 
        System.out.println("Reversed string is " + s); 
    }       
}
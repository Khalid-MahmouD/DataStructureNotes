#include<bits/stdc++.h>
using namespace std; 
void reverse(char*ch){
    stack<char>st;
    int n = strlen(ch);
    for(int i=0;i<n;++i)
        st.push(ch[i]); 
    for(int i=0;i<n;++i){
        ch[i] = st.top();
        st.pop();
    }
}
// void swap(char*a, char*b){
//     char temp =*a;
//     *a = *b;
//     *b = temp;
// }
// void reverse(char ch[]){
//     int n = strlen(ch),i;
//     for(i=0;i<n/2;++i)
//         swap(&ch[i],&ch[n-i-1]);
// }
int main(){
    char ch[] = "abcd";
    // reverse(ch);
    // cout << "Abrka Dabra: " << ch;
    reverse(ch);
    cout << ch << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void printArray(int a[],int n){
     int i;
     for(i=0;i<n;++i)
         cout << a[i] << " ";
     cout <<"\n";
}

// o(n^2)
void insertionSort(int a[], int size){
 int i, j, cur;
 for(int i=1; i < size; ++i){
    j = i-1;
    cur = a[i];
// cout << a[i]<<" " << a[j]<<" " << a[j+1] <<" \n"; 
 while(j>=0 && cur < a[j]){
        a[j+1] = a[j];
        j--;
    }
    a[j+1] = cur;
    // printArray(a,size);
 }
}
int main(){
int a[]= {7, 8, 5, 2, 4, 6, 3};
int n = sizeof(a)/sizeof(a[0]);
insertionSort(a, n);
printArray(a, n);
}
/*
12, 11, 13, 5, 6

Let us loop for i = 1 (second element of the array) to 4 (last element of the array)

i = 1. Since 11 is smaller than 12, move 12 and insert 11 before 12
11, 12, 13, 5, 6

i = 2. 13 will remain at its position as all elements in A[0..I-1] are smaller than 13
11, 12, 13, 5, 6

i = 3. 5 will move to the beginning and all other elements from 11 to 13 will move one position ahead of their current position.
5, 11, 12, 13, 6

i = 4. 6 will move to position after 5, and elements from 11 to 13 will move one position ahead of their current position.
5, 6, 11, 12, 13 
*/
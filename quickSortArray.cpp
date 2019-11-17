#include<bits/stdc++.h>
using namespace std;
void printArray(int a[], int size){
    int i;
    for( i =0 ; i < size ; ++i)
        cout << a[i] << " ";
    cout <<"\n";
}
//
void swap(int*a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partation(int a[],int low, int high){
    int pivot = a[high]; // 5 //7
    int i = (low -1); // -1 // 1 // 2 // 3
    for(int j=low; j<= high-1; ++j){
        if(a[j] < pivot){ // 10 < 5 x // 7 < 5 x // 8 < 5 x // 9 < 5 x // 1 < 5 okay
            i++; //0       //  //   
            swap(&a[i],&a[j]);// {1,7, 8, 9, 10, 5}
        }
    }
    swap(&a[i+1],&a[high]); // 1 5 8 9 10 7 // 1 5 7 9 10 8 // 1 5 7 8 10 9 // 1 5 7 8 9 10 
    return (i+1);// 1 // 2 // 3 // 4
}
void quickSort(int a[],int low, int high){
    if (low < high){
        int pi = partation(a,low,high);
        cout << pi <<" ";printArray(a,7);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}    int arr[] = {10, 7, 8, 9, 1, 5};  

int main(){
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;
}
/*
4 10 30 40 50 70 90 80 
3 10 30 40 50 70 90 80 
2 10 30 40 50 70 90 80 
1 10 30 40 50 70 90 80 
5 10 30 40 50 70 80 90 
Sorted array: 
10 30 40 50 70 80 90 
*/
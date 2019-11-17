#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l, int m, int r){
int L[100005],R[100005], i, j, k, n1 = m - l + 1, n2 = r - m ;

    for( i=0;i<n1;++i)L[i] = arr[l+i];
    for( j=0;j<n2;++j)R[j] = arr[m+1+j];
    i=0, j=0, k=l;
while(i<n1 && j<n2){
    if(L[i] <= R[j])
        arr[k++] = L[i++];
    else
        arr[k++] = R[j++]; 
}
while(i<n1)
    arr[k++] = L[i++];
while(j<n2)
    arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr,m+1,r);
        mergeSort(arr,l,m);
        merge(arr,l,m,r);
    }
}
void printArray(int arr[],int size){
    for(int i=0;i<size;++i)cout << arr[i]<<" ";
    cout <<"\n";
}
int main(){
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
}
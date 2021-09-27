#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i;
    int r = (2*i)+1;
    if(l <= n and arr[l] > arr[largest]){
        largest = l;
    }
    if(r <= n and arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}
void buildHeap(int arr[], int n){
    for(int i = n/2; i > 0; i --){
        heapify(arr, n, i);
    }
}
void HeapSort(int arr[], int n){
    buildHeap(arr, n);
    for(int i = n; i > 1; i --){
        swap(arr, i, 1);
        heapify(arr, i-1, 1);
    }
}

int main(){
    
    int arr[7];
    arr[0] = 0;
    arr[1] = 20;
    arr[2] = 10;
    arr[3] = 30;
    arr[4] = 5;
    arr[5] = 50;
    arr[6] = 40;
    HeapSort(arr, 6);
    for(int i = 1 ; i < 7 ; i ++){
        cout << arr[i] <<" ";
    }
return 0;
}
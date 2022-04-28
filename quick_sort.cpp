#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int i = low + 1;
    int j = high;

    while (i <= j){
        if (i <= high && arr[i] < arr[low])
            i++;
        if (j > low && arr[j] > arr[low])
            j--;
        if (i < j){
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high){
    if (low<high){
        int p = partition(arr, low, high);
        quicksort(arr, low, p-1);
        quicksort(arr, p+1, high);
    }
}

int main(){

    int length;

    cout<<"Enter the length of the array: ";
    cin>>length;

    int arr[length];
    
    cout<<"Enter the elements in the array: ";
    for (int i = 0; i < length; i++)
        cin>>arr[i];

    quicksort(arr,0,length-1);
    for (int i = 0; i < length; i++)
        cout<<arr[i];
}
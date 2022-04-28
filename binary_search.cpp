#include <bits/stdc++.h>

using namespace std;

int binary_search(int arr[], int key, int length){

    int start = 0;
    int end = length;
    int mid;

    while (start <= end){
        mid = (start + end) / 2;    
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1; 
    }
    return -1;
}

int main(){

    int length, key, result;
    
    cout<<"Enter the length of the array: ";
    cin>>length;

    int arr[length];
    
    cout<<"Enter the elements in the array: ";
    for (int i = 0; i < length; i++)
        cin>>arr[i];

    cout<<"Enter the element you want to search";
        cin>>key;

    sort(arr,arr+length);
    result = binary_search(arr, key, length);

    if (result == -1)
        cout<<"Element not found";
    else    
        cout<<"Element found at index: "<<result;   
    
}
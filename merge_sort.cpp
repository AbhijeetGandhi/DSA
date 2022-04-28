#include <bits/stdc++.h>
using namespace std;

vector <int> read_vec(int length){
    vector <int> v;
    int element;
    cout<<"Enter the elements: ";
    for (int i=0; i<length; i++){
        cin>>element;
        v.push_back(element);
    }
    return v;
}

void print_vec(vector <int> v){
    for(auto& itr: v)   
        cout<<itr<<" ";
}

void merge(vector <int> &arr, int start, int mid, int end){
    vector <int> first_vector, second_vector, sorted_vector;
    int i=0;
    int j=0;

    for (int i=start; i<=mid; i++)
        first_vector.push_back(arr[i]);
    for (int i=mid+1; i<=end; i++)
        second_vector.push_back(arr[i]);

    while(i<first_vector.size() && j<second_vector.size()){
        if (first_vector[i] < second_vector[j]){
            sorted_vector.push_back(first_vector[i]);
            i++;
        }
        else{
            sorted_vector.push_back(second_vector[j]);
            j++;
        }
    }
    while(i < first_vector.size()){
        sorted_vector.push_back(first_vector[i]);
        i++;
    }
    while(j < second_vector.size()){
        sorted_vector.push_back(second_vector[j]);
        j++;
    }

    for (int i=start; i<=end; i++){
        arr[i] = sorted_vector[i-start];
    }

}

void merge_sort(vector <int> &arr, int start, int end){
    int mid;
    if (start < end){
        mid = (start+end)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);

        merge(arr, start, mid, end);
    }
}

int main(){
    int length;
    cout<<"Enter the length of the array: ";
    cin>>length;
    vector <int> v = read_vec(length);
    merge_sort(v, 0, length-1);
    print_vec(v);
}
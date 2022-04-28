#include <bits/stdc++.h>
using namespace std;

int median_of_medians(int arr[], int median_pos, int length){
    if (length < 6){
        sort(arr, arr+length);
        return arr[median_pos];
    }
    
    int subarray_count = ceil((float)length/5);
    vector <vector<int>> subarrays(subarray_count);

    for (int i=0; i<subarray_count; i++){
        for (int j=0; j<5; j++){
            if ((i*5)+j >= length)
                break;
            subarrays[i].push_back(arr[(i*5)+j]);
        }
        sort(subarrays[i].begin(), subarrays[i].end());
    }

    int medians[subarray_count];
    for (int subarray=0; subarray < subarray_count; subarray++){
        medians[subarray] = subarrays[subarray][((subarrays[subarray].size()+1)/2)-1];
    }

    int mom = median_of_medians(medians, ((subarray_count+1)/2)-1, subarray_count);

    vector <int> lower, equal, higher;
    for(int i=0; i < length; i++){
        if (arr[i] < mom)
            lower.push_back(arr[i]);
        if (arr[i] > mom)
            higher.push_back(arr[i]);
        else
            equal.push_back(arr[i]);
    }
    // lower vector la fkt array madhe convert kelay 
    int lower_array[lower.size()], higher_array[higher.size()];
    for (int i=0; i<lower.size(); i++){
        lower_array[i] = lower[i];
    }
    for (int i=0; i<higher.size(); i++){
        higher_array[i] = higher[i];
    }

    if (median_pos >= lower.size() && median_pos < lower.size() + equal.size())
        return mom;
    else if (median_pos < lower.size())
        return median_of_medians(lower_array, median_pos, lower.size());
    else
        return median_of_medians(higher_array, median_pos - lower.size()+equal.size(), higher.size());
}

int partition(int arr[], int low, int high){
    int length = high-low+1;
    int array_for_median[length];
    for (int i=low; i<=high; i++){
        array_for_median[i-low] = arr[i];
    }
    int median = median_of_medians(array_for_median, ((length+1)/2)-1, length);
    for (int i = low; i<=high; i++){
        if (arr[i] == median){
            median = i;
            break;
        }
    }
    swap(arr[low], arr[median]);
    int i = low + 1;
    int j = high;

    while(i <= j){
        while(i <= high && arr[i] < arr[low])
            i++;
        while(j > low && arr[j] > arr[low])
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;

}

void quicksort(int arr[], int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);
        cout<<pivot<<endl;
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
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
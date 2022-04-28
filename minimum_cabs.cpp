#include <bits/stdc++.h>
using namespace std; 
int main()
{
    int n;
    cout<<"Enter the number of the persons: ";
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i].second>>arr[i].first;

    sort(arr.begin(),arr.end());

    int pos=0;
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i].second>=arr[pos].first)
            pos++;
        else
            count++;
    }
    cout<<count<<endl;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define vvll vector<vector<ll>>
int main()
{
    ll n,e;
    cin>>n>>e;
    vvll arr(n,vll(n,INT_MAX));
    for(int i=0;i<e;i++)
    {
        ll x,y,cost;
        cin>>x>>y>>cost;
        arr[x-1][y-1]=cost;
        arr[y-1][x-1]=cost;
    }
    vpll spanning_tree;
    set<ll> vertices;
    ll x,y,min_cost=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]<min_cost){
                min_cost=arr[i][j];
                x=i;
                y=j;
            }
        }   
    }
    ll cost=min_cost;

    spanning_tree.push_back(make_pair(x,y));
    vpll edges;
    vertices.insert(x);
    vertices.insert(y);
    for(int i=0;i<n;i++){
        if(arr[x][i]!=INT_MAX&&vertices.find(i)==vertices.end())
            edges.push_back(make_pair(x,i));
    }
    for(int i=0;i<n;i++){
        if(arr[y][i]!=INT_MAX&&vertices.find(i)==vertices.end())
        edges.push_back(make_pair(y,i));
    }   
    while(vertices.size()!=n){
        ll minpos=0;
        for(int j=0;j<edges.size();j++){
            ll x,y;
            x=edges[j].first;
            y=edges[j].second;
            if(arr[x][y]<arr[edges[minpos].first][edges[minpos].second]){
                if((vertices.find(x)!=vertices.end()&&vertices.find(y)==vertices.end())||
                 (vertices.find(y)!=vertices.end()&&vertices.find(x)==vertices.end()))
                    minpos=j;
            }
        }
        cost+=arr[edges[minpos].first][edges[minpos].second];
        spanning_tree.push_back(edges[minpos]);
        ll newv,x=edges[minpos].first,y=edges[minpos].second;
        if(vertices.find(x)==vertices.end())
            newv=x;
        else
            newv=y;
        swap(edges[edges.size()-1],edges[minpos]);
        edges.pop_back();   
        for(int j=0;j<n;j++){
            if(arr[newv][j]!=INT_MAX&&vertices.find(j)==vertices.end())
                edges.push_back(make_pair(newv,j));
        }
        vertices.insert(newv);
    }
    for(int i=0;i<spanning_tree.size();i++)
        cout<<spanning_tree[i].first<<" "<<spanning_tree[i].second<<endl;
    cout<<"MINIMUM COST: "<<cost<<endl;
}
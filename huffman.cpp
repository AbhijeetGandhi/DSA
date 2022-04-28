#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
 
#define ll long long int
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define vch vector<char>
#define vvll vector<vector<ll>>
#define mod 1000000007

void rvec(vll &arr, ll n)
{
    for(int i=0;i<n;i++)
        cin>>arr[i];
} 

void pvec(vll &arr, ll n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

class Node
{
public:
    char ch;
    int freq;
    Node *left;
    Node *right;
    Node(char c, int f)
    {
        ch=c;
        freq=f;
        left=right=NULL;
    }
    Node(int f)
    {
        freq=f;
        left=right=NULL;
    }
};

void preorder(Node *root, map<char, string> &codes, string code)
{
    if(root)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            codes[root->ch]=code;
            return;
        }
        preorder(root->left,codes,code+"0");
        preorder(root->right,codes,code+"1");
    }
}

int main() 
{
 
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
 
    ios::sync_with_stdio(false);
    cin.tie(0); 

    string str;
    cin>>str;
    map<char,int> M;
    for(int i=0;i<str.size();i++)
        M[str[i]]++;
    vector<Node*> nodes;
    for(auto x:M)
    {
        Node *p = new Node(x.first, x.second);
        nodes.push_back(p);
    }
    while(nodes.size()>1)
    {
        int minpos=0;
        for(int i=0;i<nodes.size();i++)
        {
            if(nodes[i]->freq<nodes[minpos]->freq)
                minpos=i;
        }
        Node *p = nodes[minpos];
        swap(nodes[minpos],nodes[nodes.size()-1]);
        nodes.pop_back();
        minpos=0;
        for(int i=0;i<nodes.size();i++)
        {
            if(nodes[i]->freq<nodes[minpos]->freq)
                minpos=i;
        }
        Node *q = nodes[minpos];
        swap(nodes[minpos],nodes[nodes.size()-1]);
        nodes.pop_back();
        Node *combined = new Node(p->freq+q->freq);
        combined->left=p;
        combined->right=q;
        nodes.push_back(combined);
    }
    map<char,string> codes;
    preorder(nodes[0],codes,"");
    for(auto x:codes)
        cout<<x.first<<" "<<x.second<<endl;
    string res="";
    for(int i=0;i<str.size();i++)
        res=res+codes[str[i]];
    cout<<res<<endl;
}
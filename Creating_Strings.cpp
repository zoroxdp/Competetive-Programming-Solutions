/*
        ॐ नमः शिवाय
    Author: Deependra Singh Shekhawat
    Handle: zoroxdp
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Being(Lazy)Human
#define MOD 1000000007
#define ll long long int
#define pii pair<ll, ll>
#define mii map<ll,ll>
#define ff first
#define ss second
#define vi vector<ll>
#define pqb priority_queue<ll>
#define pqs priority_queue<ll,vi,greater<ll>>
#define mp make_pair
#define pb push_back
#define endl "\n";
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; 


void dfs(int ind, int n, string &s, set<string> &st){
    if(ind == n-1){
        st.insert(s);
        return;
    }
    for(int i = ind; i < n; i++){
        swap(s[i],s[ind]);
        dfs(ind+1,n,s,st);
        swap(s[i],s[ind]);
    }
}


int main(){

    io;
    string s; cin>>s;
    set<string> st;
    dfs(0,s.size(),s,st);
    cout<<st.size()<<endl;
    for(auto it: st){
        cout<<it<<endl;
    }
}
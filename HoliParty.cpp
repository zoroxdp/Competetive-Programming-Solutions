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




int main(){

    io;
    int n,d; cin>>n>>d;
    vector<vector<int>> vec(n);
    for(int i = 0; i < d; i++){
        int a,b; cin>>a>>b;
        a--;b--;
        vec[b].push_back(a);
    }
    int ans = INT_MAX;
    vector<int> vis(n,-1);
    for(int i = 0; i < n; i++){
        if(vis[i] == 1) continue;
        queue<int> q; 
        int temp = 1;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: vec[node]){
                if(vis[it] == -1){
                    temp++;
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        ans = min(ans,temp);
    }
    cout<<ans<<endl;

}
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

ll dp[100001];

ll dfs(ll node, vector<vector<ll>> &graph){
    if(dp[node] != 0) return dp[node];
    for(auto it: graph[node]){
        dp[node] = max(dp[node],1+dfs(it, graph));
    }
    return dp[node];
}

int main(){

    io;
    memset(dp,0,sizeof(dp));
    ll n,m; cin>>n>>m;
    vector<vector<ll>> graph(n+1);
    for(ll i = 0; i < m; i++){
        ll t1,t2; cin>>t1>>t2;
        graph[t1].push_back(t2);
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ans = max(ans, dfs(i,graph));
    }
    cout<<ans<<endl;


}
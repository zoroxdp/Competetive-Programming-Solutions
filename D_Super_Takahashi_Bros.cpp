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
#define int long long
#define pii pair<int, int>
#define mii map<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>
#define mp make_pair
#define pb push_back
#define endl "\n";
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

int fun(int n, vector<vector<int>> &stages, int ind, vector<int> &vis, vector<int> &dp){
    if(ind == n-1) return 0;
    if(ind >= n) return LLONG_MAX;
    if(dp[ind] != -1) return dp[ind];
    vis[ind] = 1;
    int lol2 = LLONG_MAX;
    if(vis[stages[ind][2]-1] == 0){
        lol2 = stages[ind][1] + fun(n, stages, stages[ind][2]-1, vis, dp);
    }
    int lol1 = stages[ind][0] + fun(n, stages, ind+1, vis, dp);
    return dp[ind] = min(lol1, lol2);
}

int32_t main(){

    io;
    int n; cin>>n;
    vector<vector<int>> stages(n, vector<int> (3,0));
    for(int i = 0; i < n; i++){
        cin>>stages[i][0]>>stages[i][1]>>stages[i][2];
    }
    vector<int> vis(n,0), dp(n, -1);
    vis[0] = true;
    int ans = fun(n, stages, 0, vis, dp);
    cout<<ans<<endl;
}
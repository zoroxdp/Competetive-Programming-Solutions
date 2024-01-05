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

ll dfs(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &dp){
    // cout<<i<<" "<<j<<endl;
    if(i < 0 || i >= n || j < 0 || j >= m) return 0;
    if(grid[i][j] == '#') return 0;
    if(i == n-1 && j == m-1){
        return dp[i][j] = 1;
    }
    if(dp[i][j] != -1) return dp[i][j];
    ll temp = dfs(i+1,j,n,m,grid,dp)%MOD;
    temp = (temp+dfs(i,j+1,n,m,grid,dp))%MOD;
    
    return dp[i][j] = temp;
}


int main(){

    io;
    int n,m; cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<int>> dp(n,vector<int> (m,-1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }
    ll ans = dfs(0,0,n,m,grid,dp);
    cout<<ans<<endl;

}
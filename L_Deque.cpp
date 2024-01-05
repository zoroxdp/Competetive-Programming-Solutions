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
#define int long long int
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

int dp[3000][3000][2];


int32_t main(){

    io;
    int n; cin>>n;
    vi arr(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int i = 0; i < n; i++){
        dp[i][i][0] = arr[i];
        dp[i][i][1] = 0;
    }
    for(int gap = 1; gap < n; gap++){
        for(int l = 0; l + gap < n; l++){
            int r = l+gap;
            dp[l][r][0] = max(arr[l] + dp[l+1][r][1], arr[r] + dp[l][r-1][1]);
            dp[l][r][1] = min(dp[l+1][r][0], dp[l][r-1][0]);
        }
    }
    int x = dp[0][n-1][0];
    int ans = x*2 - sum;
    cout<<ans<<endl;

}
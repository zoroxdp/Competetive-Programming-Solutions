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

const int N = 101, K = 100001;
int n;
int dp[N][K];

// int dfs(int k, vector<int> &arr, int ind){
//     if(k == 0 && ind <= n) return 1;
//     if(ind == n && k != 0) return 0;
//     if(dp[ind][k] != -1) return dp[ind][k];
//     int temp = 0;
//     for(int i = 0; i <= arr[ind]; i++){
//         temp = (temp + dfs(k-i,arr,ind+1) % MOD) % MOD;
//     }
//     // cout<<ind<<" "<<k<<" "<<temp<<endl;
//     return dp[ind][k] = temp ;
// }

int32_t main(){

    io;
    int k;
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    vector<int> arr(n);
    for(auto &it: arr) cin>>it;
    // cout<<dfs(k,arr,0)<<endl;
    dp[0][0] = 1;
    vector<int> preSum(k+1,0);
    preSum[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            dp[i-1][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
        }
        for(int j = 0; j <= k; j++){
            dp[i][j] = dp[i-1][j];
            if(j - arr[i-1] > 0) dp[i][j] = dp[i][j] - dp[i-1][j - arr[i-1] - 1];
            dp[i][j] = ((dp[i][j] % MOD) + MOD) % MOD;
        }
    }

    cout<<dp[n][k]<<endl;
    return 0;

}
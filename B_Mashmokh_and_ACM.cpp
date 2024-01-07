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




int32_t main(){

    io;
    int n,k; cin>>n>>k;
    int dp[k+1][n+1] = {0};
    memset(dp,0,sizeof(dp));
    for(int i = 0; i <= n; i++) dp[1][i] = 1;
    for(int i = 1; i < k; i++){
        for(int j = 1; j <= n; j++){
            for(int l = 1; l*j <= n; l++){
                dp[i+1][j*l] = (dp[i+1][j*l] + dp[i][j]) % MOD;
            } 
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = (ans+dp[k][i])%MOD;
    cout<<ans<<endl;
}
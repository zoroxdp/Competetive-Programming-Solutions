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


const long long infi = 1e18;
int w[100];
int v[100];
ll dp[101][100001];

int main(){
    io;
    int n,W; cin>>n>>W;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100000; j++){
            dp[i][j] = infi;
        }
    }
    for(int i = 0; i < n; i++) cin>>w[i]>>v[i];
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i][0] = 0;
        for(int j = 1; j <= 100000; j++){
            dp[i][j] = dp[i-1][j];
            if(v[i-1] <= j){
                dp[i][j] = min(dp[i][j], w[i-1]+dp[i-1][j-v[i-1]]);
            }
        }
    }
    ll ans = 0;
    for(int val = 100000; val >= 0; val--){
        if(dp[n][val] <= W){
            ans = val;
            break;
        }
    }
    cout<<ans<<endl;

}
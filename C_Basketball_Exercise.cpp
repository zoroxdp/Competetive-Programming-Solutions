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




int main(){

    io;
    int n; cin>>n;
    vector<int> line1(n),line2(n);
    for(int i = 0; i < n; i++) cin>>line1[i];
    for(int i = 0; i < n; i++) cin>>line2[i];

    vector<vector<ll>> dp(2,vector<ll> (n+1, 0));

    for(int i = 1; i <= n; i++){
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]+line1[i-1]);
        dp[1][i] = max(dp[1][i-1], dp[0][i-1]+line2[i-1]);
    }
    cout<<max(dp[0][n], dp[1][n])<<endl;
}
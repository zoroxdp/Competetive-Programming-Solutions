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

const int N = 3000;
long double prob[N], dp[N][N];
int n;

// long double fun(int i, int h, int t){
//     if(i == n) return 1.00;
//     if(dp[i][h] != -1.00) return dp[i][h];
//     long double temp = 0;
//     if(h){
//         temp += fun(i+1, h-1,t) * prob[i];
//     }
//     if(t){
//         temp += fun(i+1, h, t-1) * (1.00-prob[i]);
//     }
//     return dp[i][h] = temp;
// }

int32_t main(){

    io;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>prob[i];
    // for(int i = (n/2+1); i <= n; i++){
    //     ans += fun(0,i,n-i);
    // }
    dp[0][0] = (1-prob[0]);
    dp[0][1] = prob[0];
    for(int i = 1; i < n; i++){
        for(int h = 0; h <= n; h++){
            dp[i][h] = dp[i-1][h]*(1-prob[i]);
            if(h > 0) dp[i][h] += dp[i-1][h-1]*prob[i];
        }
    }
    long double ans = 0;
    for(int i = n/2+1; i < 3000; i++){
        ans += dp[n-1][i];
    }
    cout<<setprecision(10)<<fixed;
    cout<<ans<<endl;
}
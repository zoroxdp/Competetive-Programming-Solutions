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

    
bool prime[1000007]; 
void Sieve(int n) 
{ 
    memset(prime, true, sizeof(prime)); 
    for (int p = 2; p * p <= n; p++) { 
        if(prime[p] == true) { 
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
} 

int fun(int h, int atk, bool flag, int dp[][]){
    if(h == 0){
        return 0;
    }
    if(h < 0){
        return 1e9;
    }
    if(dp[h][atk][flag] != -1) return dp[h][atk][flag];
    if(flag == 0){
        int temp = fun(h-atk, atk*2, 0, dp);
        for(int i = h; i >= 2; i--){
            if(prime[i] == true){
                temp = min(temp,fun(h-i,atk,1, dp));
            }
        }
        return dp[h][atk][flag] = temp+1;
    }
    else{
        return dp[h][atk][flag] = fun(h-atk,atk*2, 1, dp)+1;
    }
}


int main(){
    io;
    Sieve(1e6+1);
    int t; cin>>t; 
    while(t--){
        int h; cin>>h;
        int dp[h+1][h+1][2];
        int atk = 1;
        int ans = fun(h,atk,0,dp);
        if(ans >= 1e9) ans = -1;
        cout<<ans<<endl;
    }
}
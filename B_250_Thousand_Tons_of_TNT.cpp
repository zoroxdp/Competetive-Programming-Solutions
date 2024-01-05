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
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vi arr(n);
        for(ll i = 0; i < n; i++)cin>>arr[i];
        ll temp = 0;
        ll ans = 0;
        for(int k = 1; k <= n/2; k++){
            ll temp = 0;
            ll maxsum = INT_MIN, minsum = INT_MAX;
            for(int i = 0; i < k; i++){
                temp += arr[i];
            }
            if(maxsum < temp) maxsum = temp;
            if(minsum > temp) minsum = temp;
            for(int i = k; i < n; i++){
                temp = temp+arr[i]-arr[i-k];
                if(maxsum < temp) maxsum = temp;
                if(minsum > temp) minsum = temp;
            }
            cout<<maxsum<<" "<<minsum<<endl;
            if(maxsum-minsum > ans) ans = maxsum-minsum;
        }
        cout<<ans<<endl;
    }

}
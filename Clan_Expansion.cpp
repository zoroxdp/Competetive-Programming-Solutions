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
        int n; cin>>n;
        vector<int> arr(n);
        unordered_map<int,int> mpp;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(arr[i] != arr[i+1]) mpp[arr[i]]++;
            }
            else if(i == n-1){
                if(arr[i] != arr[i-1]) mpp[arr[i]]++;
            }
            else{
                if(arr[i] != arr[i+1]) mpp[arr[i]]++;
                if(arr[i] != arr[i-1]) mpp[arr[i]]++;
            }
        }
        int ans, freq = 0;
        for(auto it: mpp){
            if(it.second > freq){
                // cout<<it.first<<" "<<it.second<<endl;
                ans = it.first;
                freq = it.second;
            }
        }
        cout<<ans<<endl;
    }

}
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
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(auto &it: arr) cin>>it;
        sort(arr.begin(), arr.end());
        vector<int> arr1, arr2;
        bool flag  = true;
        for(auto &it: arr){
            if(flag){
                arr1.push_back(it);
            } else {
                arr2.push_back(it);
            }
            flag = !flag;
        }
        reverse(arr2.begin(), arr2.end());
        vector<int> fin;
        for(auto &it: arr1) fin.push_back(it);
        for(auto &it: arr2) fin.push_back(it);
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            ans += fin[i]+fin[i+1];
        }
        cout<<ans<<endl;
    }

}
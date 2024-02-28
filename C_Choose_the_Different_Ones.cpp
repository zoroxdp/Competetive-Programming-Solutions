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


void solve(){
    int n,m,k; cin>>n>>m>>k;
    if(k % 2 != 0){
        cout<<"NO"<<endl;
        return;
    }
    vector<int> arr1(n), arr2(m);
    for(int i = 0; i < n; i++) cin>>arr1[i];
    for(int i = 0; i < m; i++) cin>>arr2[i];
    unordered_set<int> st1,st2;
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    for(int i = 0; i < n; i++) if(arr1[i] <= k) st1.insert(arr1[i]);
    for(int i = 0; i < m; i++) if(arr2[i] <= k) st2.insert(arr2[i]);
    if(st1.size() < k/2 || st2.size() < k/2) {
        cout<<"NO"<<endl;
        return;
    }        
    else{
        set<int> st;
        for(auto it: st1) st.insert(it);
        for(auto it: st2) st.insert(it);
        for(int i = 1; i <= k; i++){
            if(st.find(i) == st.end()){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    return;
}

int32_t main(){
    io;
    int t; cin>>t;
    while(t--){
        solve();
    }

}
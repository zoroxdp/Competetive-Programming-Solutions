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
    int n,x; cin>>n>>x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    vector<int> nextState(x+1,0);
    nextState[0] = 1;
    for(int i = n-1; i >= 0; i--){
        vector<int> currState(x+1,0);
        currState[0] = 1;
        for(int s = 1; s <= x; s++){
            int skip = nextState[s];
            int pick = 0;
            if(arr[i] <= s){
                pick = currState[s-arr[i]];
            }
            currState[s] = (skip+pick)%MOD;
        }
        nextState = currState;
    }
    cout<<nextState[x]<<endl;
}
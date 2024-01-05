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
    int x,y; cin>>x>>y;
    int n; cin>>n;
    int rem = n%6;
    int ans = 0;
    if(rem == 0) ans = x-y;
    else if(rem == 1) ans = x;
    else if(rem == 2) ans = y;
    else if(rem == 3) ans = y-x;
    else if(rem == 4) ans = -x;
    else if(rem == 5) ans = -y;
    cout<<(ans%MOD+MOD)%MOD<<endl;
    // x, y, y - x,  - x,  - y, x - y, x, y, y - x,
}
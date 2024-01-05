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

ll fun(ll n){
    ll p = n, res = 1; 
    while(p > 0){
        if(p%2 == 1){
            res = res*n;
        }
        p = p/2;
        n = n*n;
    }
    return res;
}


int main(){

    io;
    ll n; cin>>n;
    ll low = 1, high = 20;
    while(low <= high){
        ll mid = low+(high-low)/2;
        ll temp = fun(mid);
        if(temp == n){
            cout<<mid<<endl;
            return 0;
        }
        else if(temp < n) low = mid+1;
        else high = mid-1;
    }
    cout<<-1<<endl;

}
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
    ll n,m,a;
    cin>>n>>m>>a;
    if(n%a == 0 && m%a == 0){
        cout<<(n/a)*(m/a)<<endl;
    }
    else{
        if(n%a == 0){
            m = m-(m%a);
            ll ans = (n/a)*(m/a) + 1;
            cout<<ans<<endl;
        }
        else if(m%a == 0){
            n = n-(n%a);
            ll ans = (n/a)*(m/a) + 1;
            cout<<ans<<endl;
        }
        else{
            n = n-(n%a);
            m = m - (m%a);
            ll ans = (n/a)*(m/a)+3;
            cout<<ans<<endl;
        }
    }

}
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
    ll n; cin>>n;
    if(((n*(n+1))/2) % 2 != 0){
        cout<<"NO"<<endl;
        return 0;
    }
    ll target = (n*(n+1))/4;
    unordered_set<int> st1,st2;
    for(ll i = 1; i <= n; i++) st1.insert(i);
    ll sum = 0, i = n;

    while(sum != target){
        if(sum+i <= target){
            st1.erase(i);
            st2.insert(i);
            sum+=i;
            i--;
        }
        else{
            i = target-sum;
        }
    }
    cout<<"YES"<<endl;
    cout<<st1.size()<<endl;
    for(auto it: st1) cout<<it<<" ";
    cout<<endl;
    cout<<st2.size()<<endl;
    for(auto it: st2) cout<<it<<" ";
    cout<<endl;
    return 0;

}
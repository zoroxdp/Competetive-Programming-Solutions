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
    int n; cin>>n;
    string s; cin>>s;
    unordered_map<char, int> mp;
    int start = 0, end = 1;
    int ans = 0;
    mp[s[0]] = 1;
    while(end < n){
        if(s[end] == s[end-1]){
            int temp = end-start+1;
            if(mp[s[end-1]] < temp){
                mp[s[end-1]] = temp;
            }
            end++;
        }
        else{
            int temp = end-start;
            if(mp[s[end-1]] < temp){
                mp[s[end-1]] = temp;
            }
            start = end;
            end++;
        }
    }
    for(auto it: mp) ans += it.second;
    cout<<ans<<endl;
}
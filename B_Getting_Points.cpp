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
    int tc; cin>>tc;
    while(tc--){
        ll n,p,l,t; cin>>n>>p>>l>>t;
        ll tasks = n%7==0 ? n/7: n/7 + 1;
        ll days = tasks%2 == 0 ? tasks/2 : tasks/2 + 1;
        // cout<<tasks<<"  "<<days<<endl;
        ll curr = (days*t*2) + (days*l);
        if(tasks%2 == 1) curr -= t;
        // cout<<"Curr "<<curr<<endl;
        if(p > curr){
            ll remp = p - curr;
            // cout<<"Rem: "<<remp<<endl;
            days += remp%l == 0 ? remp/l : remp/l + 1;
            // cout<<days<<endl;
        }
        ll total = tasks*t + days*l;
        bool flag = true;
        if(total > p){
            ll diff = total-p;
            if(tasks%2 == 1){
                if(diff-(l+t) >= p){
                    diff -= l+t;
                    days--;
                    tasks--;
                }
            }
            
            if(diff != 0){
                days -= diff/(l+(2*t));
            }
        }
        cout<<n-days<<endl;
    }

}
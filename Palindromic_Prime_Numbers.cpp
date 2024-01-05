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


void fun(vector<bool> &isPrime){
    for(int i = 2; i * i <= 1e5; i++){
        if(isPrime[i]){
            for(int j = i*i; j <= 1e5; j += i){
                isPrime[j] = false;
            }
        }
    }
}

void check(vector<bool> &isPrime, vector<pair<int,int>> &pal){
    for(int i = 2;i <= 1e5; i++){
        if(isPrime[i] == false) continue;
        string str = to_string(i);
        string rev = str;
        reverse(rev.begin(), rev.end());
        if(rev == str){
            pal.push_back({str.size(), i});
        } 
    }
}

int main(){

    io;
    vector<bool> isPrime(1e5+1, true);
    vector<pair<int,int>> pal;
	isPrime[0] = false;
    isPrime[1] = false;
	fun(isPrime);
    check(isPrime, pal);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int countEven = 0, count = 0;
        for(int i = 0; i < n; i++){
            if((pal[i].first)%2 == 0) countEven++;
            else count++;
        }
        cout<<countEven<<" "<<count<<endl;
    }

}
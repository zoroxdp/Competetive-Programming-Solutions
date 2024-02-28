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
    long long n; cin>>n;
    vector<long long> arr(n);
    for(long long i = 0; i < n; i++) cin>>arr[i];
    long long ini = 0;
    long long temp = 0;
    long long total = 0;
    for(long long i = 0; i < arr.size(); i++){
        total += arr[i];
        if(temp + arr[i] < 0){
            ini += abs(temp+arr[i]);
            temp = 0;
        }
        else{
            temp += arr[i];
        }
    }
    total += ini;
    cout<<total<<endl;

}
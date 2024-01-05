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
    int n; cin>>n;
    vector<int> arr(n);
    for(auto &it: arr) cin>>it;
    int l = 0, r = 0;
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            l = i;
            while(arr[i] > arr[i+1] && i < n-1){
                i++;
            }
            r = i;
            break;
        }
    }
    if(l == 0 && r == n-1){
        cout<<"yes"<<endl;
        cout<<l+1<<" "<<r+1<<endl;
        return 0;
    }
    if(r == n-1){
        if(arr[r] > arr[l-1]){
            cout<<"yes"<<endl;
            cout<<l+1<<" "<<r+1<<endl;
            return 0;
        }
    }
    for(int i = l; i > 0; i--){
        if(arr[r] < arr[i-1] || arr[i] < arr[i-1]){
            cout<<"no"<<endl;
            return 0;
        }
    }
    for(int i = r; i < n-1; i++){
        if(arr[l] > arr[i+1] || arr[i] > arr[i+1]){
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    if(r >= n) r = n-1;
    cout<<l+1<<" "<<r+1<<endl;


}
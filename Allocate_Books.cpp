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



int check(vector<int> &arr, int pages, int m){
    int count = 1, pagesCount = 0;
    for(int i = 0; i < arr.size(); i++){
        if(pagesCount + arr[i] <= pages){
            pagesCount += arr[i];
        }
        else{
            count++;
            pagesCount = arr[i];
        }
    }
    return count;
}


int main(){

    io;
    int n; cin>>n;
    vector<int> arr(n); 
    for(int i = 0; i < n; i++) cin>>arr[i];
    int m; cin>>m;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = (low+high)/2;
        int count = check(arr,mid,m);
        if(count > m){
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<high+1<<endl;
}
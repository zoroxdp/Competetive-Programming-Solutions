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
    int t; cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> arr(n);
        int sum = 0;
        for(auto &it: arr){
            cin>>it;
            sum += it;
        }
        while(q--){
            int x; cin>>x;
            bool flag = false;
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    int temp = sum-arr[i]-arr[j];
                    temp *= 2;
                    temp += arr[i]+arr[j];
                    if(temp == x){
                        flag = true;
                        swap(arr[0],arr[i]);
                        swap(arr[n-1], arr[j]);
                        for(int i = 0; i < n; i++){
                            cout<<arr[i]<<" ";
                        }
                        cout<<endl;
                        break;
                    }
                }
                if(flag == true) break;
            }
            if(!flag){
                cout<<-1<<endl;
            }
        }
    }
}
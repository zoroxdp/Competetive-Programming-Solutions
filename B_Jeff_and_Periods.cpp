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
    map<int,vector<int>> mpp;
    for(int i = 0; i< n; i++){
        int x; cin>>x;
        mpp[x].push_back(i);
    }
    vector<pair<int,int>> ans;
    for(auto &[key, val]: mpp){
        int vecSize = val.size();
        if(vecSize == 1){
            ans.push_back({key,0});
        }
        else if(vecSize == 2){
            ans.push_back({key,val[1]-val[0]});
        }
        else{
            int diff = val[1]-val[0];
            bool flag = true;
            for(int i = 2; i < vecSize; i++){
                if(val[i]-val[i-1] != diff){
                    flag = false;
                    break;
                }
            }   
            if(flag == true){
                ans.push_back({key,diff});
            }
        }   
    }
    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
    
}


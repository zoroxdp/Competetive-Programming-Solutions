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
    int x,y; cin>>x>>y;
    if((x== 0 && y == 0) || (x == 1 && y == 0)){
        cout<<0<<endl;
    }
    else if(x == 0 && y == 1){
        cout<<2<<endl;
    }
    else if(x == -1 && y == 0){
        cout<<3<<endl;
    }
    else if(x >= 0 && y >= 0){
        if(x >= y){
            cout<<(x-1)*4+1<<endl;
        }
        else{
            cout<<(x-1)*4+2<<endl;
        }
    }
    else if(x >= 0 && y < 0){
        y = -1 * y;
        if(y < (x-1)){
            cout<<(y*4)<<endl;
        }
        else{
            cout<<(y*4)+1<<endl;
        }
    }
    else if(x <= 0 && y >= 0){
        x = -1 * x;
        if(x < y){
            cout<<x*4-1<<endl;
        }
        else{
            cout<<x*4-2<<endl;
        }
    }
    else if(x < 0 && y <= 0){
        x = -1*x;
        y = -1*y;
        if(x < y){
            cout<<x*4<<endl;
        }
        else{
            cout<<x*4-1<<endl;
        }
    }

}
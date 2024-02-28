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
        int a,b,l; cin>>a>>b>>l;
        int i = 0, j = 0;
        int ans = 0;
        unordered_set<int> st;
        while(true){
            j = 0;
            int val1 = pow(a, i);
            if(val1 > l) break;
            while(true){
                int val2 = pow(b,j);
                if(val1*val2 > l) break;
                else if(l%(val1*val2) == 0){
                    st.insert(l/(val1*val2));
                } 
                j++;
            }
            i++;
        }
        cout<<st.size()<<endl;
    }

}
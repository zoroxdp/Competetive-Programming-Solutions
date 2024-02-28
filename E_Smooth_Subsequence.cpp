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

int ans = 1;


class DisjointSet{
    public: vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = i;
        }
    }
    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] = max(size[ulp_v],size[ulp_u]);
            ans = max(ans, size[ulp_v]);
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] = max(size[ulp_v],size[ulp_v]);
            ans = max(ans, size[ulp_u]);
        }
    }
};

int32_t main(){
    io;
    int n,d; cin>>n>>d;
    vector<int> nodes(n,0);
    for(auto &it: nodes) cin>>it;
    DisjointSet ds(n);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(abs(nodes[i]-nodes[j]) <= d){
                ds.unionBySize(i,j);
            }
        }
    }
    cout<<ans<<endl;
}
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

int n,m,d;

int check(int k, vector<vector<int>> &mat){
    int temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int diff = abs(mat[i][j] - k);
            if(diff % d != 0){
                return INT_MAX;
            }
            else{
                temp += diff/d;
            }
        }
    }
    return temp;
}

int32_t main(){

    io;
    cin>>n>>m>>d;
    vector<vector<int>> mat(n,vector<int> (m));
    int r = 0, l = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mat[i][j];
            r = max(mat[i][j], r);
            l = min(mat[i][j], l);
        }
    }
    if(l == r){
        cout<<0<<endl;
        return 0;
    }
    int ans = INT_MAX;
    for(int k = l; k <= r; k++){
        int temp = check(k,mat);
        // cout<<k<<" "<<temp<<endl;
        ans = min(ans, temp);

    }
    if(ans == INT_MAX){
        cout<<-1<<endl;
    }
    else cout<<ans<<endl;


}
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
    int n,m,op;
    cin>>n>>m>>op;
    vector<vector<char>> mat(n, vector<char> (m,'.'));
    int r = n-1, c = 0;
    int face = 0;
    for(int i = 0; i < op; i++){
        if(mat[r][c] == '.'){
            mat[r][c] = '#';
            if(face == 0){
                c++;
                if(c == m) c = 0;
                face = 1;
            }
            else if(face == 1){
                r--;
                if(r < 0) r = n-1;
                face = 2;
            }
            else if(face == 2){
                c--;
                if(c < 0) c = m-1;
                face = 3;
            }
            else{
                r++;
                if(r == n) r = 0;
                face = 0;
            }
        }
        else{
            mat[r][c] = '.';
            if(face == 0){
                c--;
                if(c < 0) c = m-1;
                face = 3;
            }
            else if(face == 1){
                r++;
                if(r == n) r = 0;
                face = 0;
            }
            else if(face == 2){
                c++;
                if(c == m) c = 0;
                face = 1;
            }
            else{
                r--;
                if(r < 0) r = n-1;
                face = 2;
            }
        }
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }

}
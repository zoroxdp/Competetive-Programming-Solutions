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

int n,m;
const int delcol[] = {1,0,-1,0}, delrow[] = {0,1,0,-1};

void dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &vis, int col){
    if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '-' || vis[i][j] == 1) return;
    if(col == 0){
        board[i][j] = 'B';
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            dfs(i+delrow[k], j+delcol[k], board, vis, 1-col);
        }
    }
    else{
        board[i][j] = 'W';
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++){
            dfs(i+delrow[k], j+delcol[k], board, vis, 1-col);
        }
    }
}


int32_t main(){

    io;
    cin>>n>>m;
    vector<vector<char>> board(n,vector<char> (m));
    vector<vector<int>> vis(n,vector<int> (m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>board[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == '.'){
                dfs(i,j,board,vis, 0);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}
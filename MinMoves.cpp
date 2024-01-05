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




int main(){

    io;
    int n,m;
    cin>>n>>m;
    vector<vector<char>> mat(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mat[i][j];
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < m; i++){
        if(mat[0][i] == 'X'){
            int temp = 0;
            vector<vector<int>> vis(n,vector<int> (m,-1));
            queue<pair<int,int>> que;
            que.push({0,i});
            vis[0][i] = 1;
            while(!que.empty()){
                int r = que.front().first;
                int c = que.front().second;
                que.pop();
                for(int p = -1; p <= 1; p++){
                    for(int q = -1; q <= 1; q++){
                        int row = r + p;
                        int col = c + q;
                        cout<<row<<" "<<col<<endl;
                        if(row >= 0 && row < n && col >= 0 && col < m && vis[row][col] == -1 && mat[row][col] == 'X'){
                            temp++;
                            que.push({row,col});
                            if(row == 0){
                                ans = min(ans, temp);
                                p = 3; q = 3;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;

}
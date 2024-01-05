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
    int t,sx,sy,ex,ey; cin>>t>>sx>>sy>>ex>>ey;
    string s; cin>>s;
    unordered_set<char> st;
    if(ex-sx > 0) st.insert('E');
    else if(ex-sx < 0) st.insert('W');
    if(ey-sy > 0) st.insert('N');
    else if(ey-sy < 0) st.insert('S');
    int timetake = 0, i = 0;
    while(true){
        if(st.find(s[i]) != st.end()){
            if(s[i] == 'N' && ey > sy){
                sy++;
            }
            else if(s[i] == 'S' && ey < sy){
                sy--;
            }
            else if(s[i] == 'E' && ex > sx){
                sx++;
            }
            else if(s[i] == 'W' && ex < sx){
                sx--;
            }
        }
        timetake++;
        if(sx == ex && ey == sy){
            break;
        }
        i++;
        if(i == t){
            timetake = -1;
            break;
        }
    }
    cout<<timetake<<endl;

}
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
    string s; cin>>s;
    unordered_map<char,int> mpp;
    for(auto it: s){
        mpp[it]++;
    }
    bool flag = false;
    pair<char,int> p;
    for(auto it: mpp){
        char key = it.first;
        int val = it.second;
        if(val%2 != 0){
            if(flag == false){
                flag = true;
                p = {key,val};
            }
            else{
                cout<<"NO SOLUTION"<<endl;
                return 0;
            }
        }
    }
    mpp.erase(p.first);
    int i = 0, j = s.size()-1;
    for(auto it: mpp){
        char key = it.first;
        int val = it.second;
        for(int k = 0; k < val/2; k++){
            s[i] = key;
            s[j] = key;
            i++;
            j--;
        }
    }
    if(flag == true){
        int val = p.second;
        char ch = p.first;
        for(int k = 0; k <= val/2; k++){
            s[i] = ch;
            s[j] = ch;
            i++;j--;
        }
    }
    cout<<s<<endl;

}
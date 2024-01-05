#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int x,y,c; cin>>x>>y>>c;
        if(y<x) cout<<x<<endl;
        else if(x+c >= y) cout<<y<<endl;
        else cout<<y+(y-(x+c))<<endl;
    }
}
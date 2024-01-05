/*
        ॐ नमः शिवाय
    Author: Deependra Singh Shekhawat
    Handle: zoroxdp
*/


#include <bits/stdc++.h>
using namespace std;





int main(){

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i = 0; i <= n; i++){
            cin>>arr[i];
        }
        unordered_map<int,int> mpp;
        vector<pair<int,int>> vec;
        for(auto it: arr) cout<<it<<" ";
        cout<<endl;
        for(int i = 0; i < n; i++){
            cout<<i<<endl;
            if(mpp.find(arr[i]) == mpp.end()){
                mpp[arr[i]] = i;
                cout<<mpp[arr[i]]<<endl;
            }
            else{
                vec.push_back({mpp[arr[i]],i});
            }
            if(vec.size() == 2) break;
        }
        vector<int> ans(n,1);
        ans[vec[0].first]=1;
        ans[vec[0].second]=2;
        ans[vec[1].first]=1;
        ans[vec[1].second]=3;
        for(auto it: ans) cout<<it<<" ";
        cout<<endl;
    }

}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        unordered_map<int,int> mpp,freq;
        vector<pair<int,int>> vec;
        bool flag = false;
        for(auto it: arr){
            freq[it]++;
            if(freq[it] >= 4) flag = true;
        }
        if(flag == true){
            cout<<-1<<endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            if(mpp.find(arr[i]) == mpp.end()){
                mpp[arr[i]] = i;
            }
            else{
                vec.push_back({mpp[arr[i]],i});
            }
        }
        if(vec.size() == 0 || vec.size() == 1){
            cout<<-1<<endl;
            continue;
        }
        vector<int> ans(n,1);
        ans[vec[0].first]=2;
        ans[vec[0].second]=1;
        ans[vec[1].first]=2;
        ans[vec[1].second]=3;
        for(auto it: ans) cout<<it<<" ";
        cout<<endl;
    }
}
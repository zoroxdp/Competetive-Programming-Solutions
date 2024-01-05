#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(2*n);
        for(int i = 0; i < 2*n; i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        int len = 0;
        vector<int> x,y;
        int i = n-1,j = n;
        while(i>=0){
            x.push_back(arr[i]);
            y.push_back(arr[j]);
            i--;j++;
        }
        for(int i = 0; i < n-1; i++){
            len += abs(x[i+1]-x[i]);
            len += abs(y[i+1]-y[i]);
        }
        cout<<len<<endl;
        for(int i = 0; i < n; i++){
            cout<<x[i]<<" "<<y[i]<<endl;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin>>arr[i];
        bool flag = true;
        for(int i = 1; i < n; i++){
            if((i&(i+1)) == 0){
                continue;
            } 
            else{
                for(int j = i+1; j < n; j++){
                    if((j&(j-1)) == 0) continue;
                    if(arr[i] > arr[j]){
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag == true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
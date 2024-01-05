#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    int ans = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if((arr[i].size()+arr[j].size())%2 == 0){
                string temp = arr[i]+arr[j];
                int h = temp.size()/2;
                int sum1 = 0, sum2 = 0;
                for(int i = 0; i < h; i++){
                    sum1 += temp[i]-'0';
                    sum2 += temp[i+h]-'0';
                }
                if(sum1 == sum2) ans++;
            }
        }
    }
    cout<<ans<<endl;
}
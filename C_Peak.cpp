#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    int high = 0;
    int ans = 0;
    for(int low = 0; low < n; low++){
        while(high < n && arr[high]-arr[low]+1 <= m){
            ans = max(ans,high-low+1);
            high++;
        }
    }
    cout<<ans<<endl;
}
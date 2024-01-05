/*
        ॐ नमः शिवाय
    Author: Deependra Singh Shekhawat
    Handle: zoroxdp
*/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n";

bool check(vector<long long> &arr, long long dist, long long n, long long d){
    long long cnt = 1, last = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] - last >= dist){
            cnt++;
            last = arr[i];
        }
        if(cnt >= d) return true;
    }
    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n,c; cin>>n>>c;
        vector<long long> arr(n);
        for(int i = 0; i < n; i++) cin>>arr[i];
        sort(arr.begin(), arr.end());
        long long low = 1, high = arr[n-1]-arr[0];
        while(low <= high){
            long long mid = low+(high-low)/2;
            if(check(arr,mid,n,c)){
                low = mid+1;
            }
            else high = mid-1;
        }
        cout<<high<<endl;
    }

}
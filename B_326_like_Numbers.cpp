#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  int temp = n;
  int hun = temp/100;
  temp = temp%10;
  int ten = temp/10;
  int num;
  for(int i = hun; i <= 9; i++){
    for(int j = ten; j <= 9; j++){
        if(i*j < 10){
          num = i*100+j*10+(i*j);
          if(num >= n){
            cout<<num<<endl;
            return 0;
          }
        }
    }
  }
}
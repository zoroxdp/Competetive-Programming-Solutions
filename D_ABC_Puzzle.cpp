#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<string> &mat, int row, int col, char ch){
    for(int i = 0; i < mat.size(); i++){
        if(mat[i][col] == ch && i != row) return false;
        if(mat[row][i] == ch && i != col) return false;
    }
    return true;
}

bool fun(vector<string> &mat, int &n, string &r, string &c){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == '.'){
                if(i == 0 && isValid(mat,i,j,c[i])){
                    mat[i][j] = c[i];
                    if(fun(mat,n,r,c) == true) return true;
                    else mat[i][j] = '.';
                }
                else if(j == 0 && isValid(mat,i,j,r[i])){
                    mat[i][j] = r[j];
                    if(fun(mat,n,r,c) == true) return true;
                    else mat[i][j] = '.';
                }
                else{
                    for(char ch = 'A'; ch < 'D'; ch++){
                        if((i != 0 || j != 0) && isValid(mat,i,j,ch)){
                            mat[i][j] = ch;
                            if(fun(mat,n,r,c) == true) return true;
                            else mat[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n; cin>>n;
    string r,c; cin>>r>>c;
    string temp(n,'.');
    vector<string> mat;
    for(int i = 0; i < n; i++) mat.push_back(temp);
    if(fun(mat,n,r,c) == true) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    for(auto it: mat) cout<<it<<endl;
}
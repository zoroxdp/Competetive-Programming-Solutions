/*
        ॐ नमः शिवाय
    Author: Deependra Singh Shekhawat
    Handle: zoroxdp
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Being(Lazy)Human
#define MOD 1000000007
#define int long long int
#define pii pair<int, int>
#define mii map<int,int>
#define ff first
#define ss second
#define vi vector<int>
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>
#define mp make_pair
#define pb push_back
#define endl "\n";
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 


int n;
const int N = 301;
long double dp[N][N][N];

// long double fun(int zero, int one, int two, int three){
//     if(one+two+three == 0) return 0;
//     if(dp[one][two][three] != -1.00) return dp[one][two][three];
//     long double ans = n;
//     if(one) ans += one*fun(zero+1,one-1,two,three);
//     if(two) ans += two*fun(zero,one+1,two-1,three);
//     if(three) ans += three*fun(zero,one,two+1,three-1);
//     ans /= (long double)(n-zero);
//     return dp[one][two][three] = ans;
// }

int32_t main(){

    io;
    cin>>n;
    int cnt[4];
    memset(cnt,0,sizeof(cnt));
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    dp[0][0][0] = 0;
    for(int three = 0; three <= n; three++){
        for(int two = 0; two <= n; two++){
            for(int one = 0; one <= n; one++){
                int zero = n-three-two-one;
                if(zero == n) continue;
                if(three+two+one > n) continue;
                long double val = 1;
                if(three > 0) val += (1.00 * three / n) * dp[one][two+1][three-1];
                if(two > 0) val += (1.00 * two / n) * dp[one+1][two-1][three];
                if(one > 0) val += (1.00 * one / n) * dp[one-1][two][three];
                dp[one][two][three] = val / (1 - 1.0 * zero / n);
            }
        }
    }
    cout<<setprecision(10)<<fixed;
    cout<<dp[cnt[1]][cnt[2]][cnt[3]]<<endl;


}
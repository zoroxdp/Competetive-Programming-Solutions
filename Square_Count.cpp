#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

long long count_quadruples(vector<long long>& A) {
  // Precompute the greatest common divisors of all subarrays of A.
  vector<vector<long long>> gcd_table(A.size(), vector<long long>(A.size()));
  for (int i = 0; i < A.size(); ++i) {
    gcd_table[i][i] = A[i];
    for (int j = i + 1; j < A.size(); ++j) {
      gcd_table[i][j] = gcd(gcd_table[i][j-1], A[j]);
    }
  }

  // Count the number of quadruples that satisfy the problem conditions.
  long long count = 0;
  for (int L1 = 1; L1 < A.size() - 1; ++L1) {
    for (int R1 = L1 + 1; R1 < A.size(); ++R1) {
      for (int L2 = R1 + 1; L2 < A.size(); ++L2) {
        for (int R2 = L2 + 1; R2 < A.size(); ++R2) {
          if ((gcd_table[L1][R1] * gcd_table[L2][R2]) % 998244353 == 0) {
            count++;
          }
        }
      }
    }
  }

  return count;
}

int main() {
  int t; cin>>t;
  while(t--){
    long long n; cin>>n;
    vector<long long> arr(n);
    for(long long i = 0; i < n; i++){
        cin>>arr[i];
    }
    long long count = count_quadruples(arr);
    cout << count << endl;
  }
  return 0;
}

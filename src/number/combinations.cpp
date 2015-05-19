/**
 * Combinations (n choose k) using Pascal's triangle O(n^2)
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000, MOD = 1e9+7;
long long comb[MAXN+1][MAXN+1];

void build_table() {
    for (int i=0; i<=MAXN; i++) {
        for (int j=0; j<=i; j++) {
            comb[i][j] = !j ? 1 : (comb[i-1][j-1] + comb[i-1][j]) % MOD;
        }
    }
}

/**
 * Example usage
 */
int main() {
    build_table();
    cout << "60 choose 9 mod 10^9+7 is " << comb[60][9] << "\n";
    cout << "1000 choose 500 mod 10^9+7 is " << comb[1000][500] << "\n";
    return 0;
}

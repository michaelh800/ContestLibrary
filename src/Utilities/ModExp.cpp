/**
 * Fast modular exponentiation
 */

#include <iostream>
using namespace std;

long long modExp(long long n, long long exp, long long mod) {
    long long res = 1;
    while (exp) {
        if (exp % 2 == 1) res = (res * n) % mod;
        n = (n * n) % mod;
        exp /= 2;
    }
    return res;
}

/**
 * Example usage
 */
int main() {
    ios::sync_with_stdio(false);
    long long base = 9688563, exp = 45896, mod = 71;
    cout << base << " ^ " << exp << " mod " << mod << " = " << modExp(base, exp, mod) << "\n";
    return 0;
}

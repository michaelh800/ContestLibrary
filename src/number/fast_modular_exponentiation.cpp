/**
 * Fast modular exponentiation
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod_exp(ll n, ll exp, ll mod) {
    ll res = 1;
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
    ll base = 9688563, exp = 45896, mod = 71;
    cout << base << " ^ " << exp << " mod " << mod << " = " << mod_exp(base, exp, mod) << "\n";
    return 0;
}

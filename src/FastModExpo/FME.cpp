#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long
#define MOD 1000000007

ull fastExp(ull n, int exp) {
    ull ans = 1;
    while (exp) {
        if (exp % 2 == 1) ans = (ans * n) % MOD;
        n = (n * n) % MOD;
        exp /= 2;
    }
    return ans % MOD;
}
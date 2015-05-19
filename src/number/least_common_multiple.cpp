/**
 * Least common multiple
 */

#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
    return a/__gcd(a, b)*b;
}

int lcm(vector<int> &arr) {
    int res = 1;
    for (const int &i : arr) res = lcm(res, i);
    return res;
}

/**
 * Example usage
 */
int main() {
    vector<int> tst = { 330, 65, 15, 11, 19 };
    cout << "The lcm of 330, 65, 15, 11, 19 is " << lcm(tst) << "\n";
    return 0;
}

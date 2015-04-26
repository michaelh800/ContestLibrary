/**
 * Least common multiple
 */

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    while (b) { int r = a % b; a = b; b = r; }
    return a;
}

int lcm(int a, int b) {
    return a/gcd(a, b)*b;
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
    ios::sync_with_stdio(0);
    vector<int> tst = { 330, 65, 15, 11, 19 };
    cout << "The lcm of 330, 65, 15 is " << lcm(tst) << "\n";
    return 0;
}

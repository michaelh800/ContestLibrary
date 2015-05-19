/**
 * Greatest common divisor using Euclid's algorithm
 */

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b) { int r = a % b; a = b; b = r; }
    return a;
}

/**
 * Example usage
 */
int main() {
    cout << "gcd of 867 and 1989 is " << gcd(867, 1989) << "\n";
    return 0;
}

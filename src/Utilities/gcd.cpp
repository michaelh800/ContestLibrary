/**
 * Greatest common divisor using Euclid's algorithm
 */

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b) { int r = a % b; a = b; b = r; }
    return a;
}

/**
 * Example usage
 */
int main() {
    ios::sync_with_stdio(false);
    cout << "gcd of 1989 and 867 is " << gcd(1989, 867) << "\n";
    cout << "gcd of 867 and 1989 is " << gcd(867, 1989) << "\n";
    cout << "gcd of 10 and 10 is " << gcd(10, 10) << "\n";
    return 0;
}

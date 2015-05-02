/**
 * Knuth-Morris-Pratt algorithm for string pattern-matching
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> build_lcp(string &p) {
    int k = 0, m = p.length();
    vector<int> lcp(m);

    for (int i=1; i<m; i++) {
        while (k && p[i] != p[k])
            k = lcp[k-1];
        if (p[i] == p[k])
            ++k;
        lcp[i] = k;
    }
    return lcp;
}

int kmp(string &s, string &p) {
    int res = 0, n = s.length(), m = p.length();
    vector<int> lcp = build_lcp(p);

    for (int i=0, k=0; i<n; i++) {
        while(k && p[k] != s[i])
            k = lcp[k-1];
        if (p[k] == s[i])
            ++k;
        if (k == m)
            ++res;
    }
    return res;
}

/**
 * Example usage
 */
int main() {
    ios::sync_with_stdio(false);
    string s = "abababababa";
    string p = "ababa";
    cout << "'" << p << "' occurs in '" << s << "' " << kmp(s, p) << " times\n";
    return 0;
}

/**
 * Knuth-Morris-Pratt algorithm for string pattern-matching
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> buildlcp(string &p) {
    int m = p.length();
    vector<int> lcp(m);
    int i = 1, k = 0;

    while (i < m) {
        if (p[k] == p[i]) {
            lcp[i++] = ++k;
        }
        else {
            if (k)
                k = lcp[k - 1];
            else
                lcp[i++] = 0;
        }
    }
    return lcp;
}

int kmp(string &s, string &p) {
    int n = s.length(), m = p.length();
    vector<int> lcp = buildlcp(p);
    int i = 0, j = 0, res = 0;

    while (i < n) {
        if (s[i] == p[j]) {
            i++;
            j++;
            if (j == m) {
                j = lcp[j-1];
                res++;
            }
        }
        else if (j > 0) {
            j = lcp[j];
        }
        else {
            i++;
        }
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

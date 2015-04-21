/**
 * Palindrome Tree O(n)
 */

// http://adilet.org/blog/25-09-14/
// http://ideone.com/YQX9jv

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

namespace PalindromeTree {
    vector<int> s, len, link;
    vector<vector<int> > to;
    int n, last, sz;

    int getLink(int v) {
        while(s[n-len[v]-2] != s[n-1]) v = link[v];
        return v;
    }

    void addLetter(int c) {
        s[n++] = c;
        last = getLink(last);
        if(!to[last][c]) {
            len [sz] = len[last] + 2;
            link[sz] = to[getLink(link[last])][c];
            to[last][c] = sz++;
        }
        last = to[last][c];
    }

    void buildPT(const string &str, int base='a', int sigma=26) {
        int m = str.length() + 1;
        s = vector<int>(m);
        len = link = vector<int>(m+1);
        to = vector<vector<int>>(m+1);
        for (auto &v : to) v = vector<int>(sigma);
        n = 0; sz = 2;
        s[n++] = -1;
        link[0] = 1;
        len[1] = -1;
        for (int i=1; i<m; i++)
            addLetter(str[i - 1] - base);
    }
}

/**
 * Example usage
 */
int main() {
    ios::sync_with_stdio(false);
    string s = "banana";
    PalindromeTree::buildPT(s);
    vector<int> pt = PalindromeTree::len;
    int sz = PalindromeTree::sz;
    for (int i=2; i<sz; i++) {
        cout << s.substr(i - pt[i] - 1, pt[i]) << "\n";
    }
    return 0;
}

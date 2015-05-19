/**
 * Palindrome Tree O(n)
 */

#include <bits/stdc++.h>
using namespace std;

namespace palindrome_tree {
    vector<int> s, len, link; vector<vector<int>> to;
    int n, last, sz;

    int get_link(int v) {
        while(s[n-len[v]-2] != s[n-1]) v = link[v];
        return v;
    }

    void add_letter(int c) {
        s[n++] = c;
        last = get_link(last);
        if(!to[last][c]) {
            len [sz] = len[last] + 2;
            link[sz] = to[get_link(link[last])][c];
            to[last][c] = sz++;
        }
        last = to[last][c];
    }

    void build_pt(const string &str, int base='a', int sigma=26) {
        int m = str.length()+1;
        s = vector<int>(m); len = link = vector<int>(m+1);
        to = vector<vector<int>>(m+1, vector<int>(sigma));
        n = 0; sz = 2;
        s[n++] = -1; link[0] = 1; len[1] = -1;
        for (int i=1; i<m; i++) add_letter(str[i-1] - base);
    }
}

/**
 * Example usage
 */
int main() {
    string s = "banana";
    palindrome_tree::build_pt(s);
    vector<int> len = palindrome_tree::len;
    int sz = palindrome_tree::sz;
    for (int i=2; i<sz; i++)
        cout << s.substr(i - len[i]- 1, len[i]) << "\n";
    return 0;
}

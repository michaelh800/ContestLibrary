#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> buildlcp(string p) {
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

int kmp(string s, string p) {
    int n = s.length(), m = p.length();
    vector<int> lcp = buildlcp(p);
    int i = 0, j = 0, res = 0;

    while (i < n) {
        if (s[i] == p[j]) {
            i++;
            j++;
            res += j == m;
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

int main() {
    return 0;
}
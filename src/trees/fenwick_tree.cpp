/**
 * Fenwick tree for counting inversions
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
int N;
int a[MAXN+1], b[MAXN+1], tree[MAXN+1];

int read(int idx) {
    int sum = 0;
    for (int i=idx; i>0; i-=(i & -i)) {
        sum += tree[i];
    }
    return sum;
}

void update(int idx, int val) {
    for (int i=idx; i<=N; i+=(i & -i)) {
        tree[i] += val;
    }
}

int inversion_count() {
    memset(tree, 0, sizeof tree);
    int ans = 0;
    for (int i=N-1; i>=0; i--) {
        ans += read(a[i]-1);
        update(a[i], 1);
    }
    return ans;
}

void compress() {
    for (int i=0; i<N; i++) b[i] = a[i];
    sort(b, b + N);
    for (int i=0; i<N; i++)
        a[i] = 1 + int(lower_bound(b, b+N, a[i]) - b);
}

/**
 * Example usage
 */
int main() {
    N = 5;
    a[0] = 2; a[1] = 3; a[2] = 8; a[3] = 6; a[4] = 1;
    compress();
    cout << inversion_count() << "\n";
    return 0;
}

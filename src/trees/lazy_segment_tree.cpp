/**
 * Segment tree with lazy propogation
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50000, MAX_SIZE = 131071; // 2^(ceil(lgn)+1)-1
int arr[MAX_N], tree[MAX_SIZE], lazy[MAX_SIZE];

void build_tree(int node, int sb, int se) {
    if (sb == se) { tree[node] = arr[sb]; return; }

    build_tree(node*2+1, sb, (sb+se)/2);
    build_tree(node*2+2, (sb+se)/2+1, se);

    tree[node] = max(tree[node*2+1], tree[node*2+2]);
}

void propogate(int node, int val) {
    int le = 2*node+1, ri = 2*node+2;

    tree[le] += val; lazy[le] += val;
    tree[ri] += val; lazy[ri] += val;

    lazy[node] = 0;
}

void update_tree(int node, int sb, int se, int qb, int qe, int val) {
    if (se < qb || sb > qe)
        return;

    if (qb <= sb && se <= qe) {
        tree[node] += val; lazy[node] += val;
        return;
    }

    if (lazy[node]) propogate(node, lazy[node]);

    update_tree(2*node+1, sb, (sb+se)/2, qb, qe, val);
    update_tree(2*node+2,(sb+se)/2+1, se, qb, qe, val);
    tree[node] = max(tree[2*node+1], tree[2*node+2]);
}

int query_tree(int node, int sb, int se, int qb, int qe) {
    if (se < qb || sb > qe)
        return INT_MIN;

    if (qb <= sb && se <= qe)
        return tree[node];

    if (lazy[node]) propogate(node, lazy[node]);

    return max(
        query_tree(2*node+1, sb, (sb+se)/2, qb, qe),
        query_tree(2*node+2, (sb+se)/2+1, se, qb, qe));
}

/**
 * Example usage
 */
int main() {
    // build tree
    int n = 10;
    for (int i=0; i<=n; i++) arr[i] = i;
    build_tree(0, 0, n);
    // updates
    update_tree(0, 0, n, 4, 7, 10);
    update_tree(0, 0, n, 7, 9, -20);
    update_tree(0, 0, n, 0, 4, 5);
    // queries
    for (int i=0; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            cout << "\nmax in range [" << i << ".." << j << "]: "
                 << query_tree(0, 0, n, i, j) << "\n";
        }
    }
    return 0;
}

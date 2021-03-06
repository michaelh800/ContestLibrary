/**
 * Lowest common ancestor using sparse table
 */

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAXN = 2e5+7, LOGN = 20;

vvi tree;
int len, tim, root;
int up[LOGN][MAXN], tin[MAXN], tout[MAXN];

void dfs(int u, int p) {
    tin[u] = tim++;
    up[0][u] = p;
    for (int i=1; i<len; i++)
        up[i][u] = up[i-1][up[i-1][u]];
    for (int &v : tree[u])
        if (v != p)
            dfs(v, u);
    tout[u] = tim++;
}

void init() {
    int n = tree.size();
    len = 1;
    while ((1 << len) <= n) ++len;
    dfs(root, root);
}

bool is_parent(int parent, int child) {
    return tin[parent] <= tin[child] &&
           tout[child] <= tout[parent];
}

int lca(int a, int b) {
    if (is_parent(a, b))
        return a;
    if (is_parent(b, a))
        return b;
    for (int i=len-1; i>=0; i--)
        if (!is_parent(up[i][a], b))
            a = up[i][a];
    return up[0][a];
}

/**
 * Example usage
 */
int main() {
    // build tree
    int n = 7;
    root = 0;
    tree = vvi(n);
    tree[0].push_back(2);
    tree[2].push_back(0);
    tree[0].push_back(3);
    tree[3].push_back(0);
    tree[2].push_back(4);
    tree[4].push_back(2);
    tree[2].push_back(5);
    tree[5].push_back(2);
    tree[3].push_back(1);
    tree[1].push_back(3);
    init();

    // queries
    cout << "LCA of 4 and 5 is " << lca(4, 5) << "\n";
    cout << "LCA of 5 and 1 is " << lca(5, 1) << "\n";
    cout << "LCA of 1 and 3 is " << lca(1, 3) << "\n";

    return 0;
}

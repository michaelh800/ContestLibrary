/**
 * Max flow using Edmonds-Karp algorithm
 */

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

int find_path(const vvi &graph, vvi &cap, vb &vis, int u, int t, int f) {
    if (u == t)
        return f;
    vis[u] = true;
    for (const int &adj : graph[u]) {
        if (!vis[adj] && cap[u][adj] > 0) {
            int df = find_path(graph, cap, vis, adj, t, min(f, cap[u][adj]));
            if (df) {
                cap[u][adj] -= df;
                cap[adj][u] += df;
                return df;
            }
        }
    }
    return 0;
}

int max_flow(const vvi &graph, vvi &cap, int s, int t) {
    for (int flow = 0;;) {
        vb vis(graph.size());
        int df = find_path(graph, cap, vis, s, t, INT_MAX);
        if (!df)
            return flow;
        flow += df;
    }
}

/**
 * Example usage
 */
int main() {
    ios::sync_with_stdio(0);
    // make sure to remove self loops and merge multiple edges here
    vvi graph = { { 1, 2 }, { 2 }, { 3 }, {} };
    vvi cap = { { 0, 3, 2, 0 }, { 0, 0, 4, 0 }, { 0, 0, 0, 6 }, { 0, 0, 0, 0 } };
    cout << max_flow(graph, cap, 0, 3) << "\n";
    return 0;
}

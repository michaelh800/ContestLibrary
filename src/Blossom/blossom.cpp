#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lca(vector<int> &match, vector<int> &base, vector<int> &p, int a, int b) {
    vector<bool> used(match.size());
    while (true) {
        a = base[a];
        used[a] = true;
        if (match[a] == -1) break;
        a = p[match[a]];
    }
    while (true) {
        b = base[b];
        if (used[b]) return b;
        b = p[match[b]];
    }
}

void markPath(vector<int> &match, vector<int> &base, vector<bool> &blossom, vector<int> &p, int v, int b, int children) {
    for (; base[v] != b; v = p[match[v]]) {
        blossom[base[v]] = blossom[base[match[v]]] = true;
        p[v] = children;
        children = match[v];
    }
}

int findPath(vector<vector<int> > &graph, vector<int> &match, vector<int> &p, int root) {
    int n = graph.size();
    vector<bool> used(n);
    for (auto &x : p) x = -1;
    vector<int> base(n);
    for (int i=0; i<n; i++) base[i] = i;

    used[root] = true;
    int qh = 0, qt = 0;
    vector<int> q(n);
    q[qt++] = root;
    while (qh < qt) {
        int v = q[qh++];

        for (int &to : graph[v]) {
            if (base[v] == base[to] || match[v] == to) continue;
            if (to == root || (match[to] != -1 && p[match[to]] != -1)) {
                int curbase = lca(match, base, p, v, to);
                vector<bool> blossom(n);
                markPath(match, base, blossom, p, v, curbase, to);
                markPath(match, base, blossom, p, to, curbase, v);
                for (int i=0; i<n; i++) {
                    if (blossom[base[i]]) {
                        base[i] = curbase;
                        if (!used[i]) {
                            used[i] = true;
                            q[qt++] = i;
                        }
                    }
                }
            }
            else if (p[to] == -1) {
                p[to] = v;
                if (match[to] == -1)
                    return to;
                to = match[to];
                used[to] = true;
                q[qt++] = to;
            }
        }
    }
    return -1;
}

int maxMatching(vector<vector<int> > &graph) {
    int n = graph.size();
    vector<int> match(n, -1), p(n);
    for (int i=0; i<n; i++) {
        if (match[i] == -1) {
            int v = findPath(graph, match, p, i);
            while (v != -1) {
                int pv = p[v];
                int ppv = match[pv];
                match[v] = pv;
                match[pv] = v;
                v = ppv;
            }
        }
    }
    int matches = 0;
    for (auto &v : match) {
        if (v != -1) matches++;
    }
    return matches / 2;
}

int main() {
    vector<vector<int> > graph(6);
    graph[0] = vector<int> { 1, 2, 4 };
    graph[1] = vector<int> { 0, 2, 4 };
    graph[2] = vector<int> { 0, 1 };
    graph[3] = vector<int> { 0, 5 };
    graph[4] = vector<int> { 1 };
    graph[5] = vector<int> { 3 };
    cout << maxMatching(graph) << endl;
    return 0;
}

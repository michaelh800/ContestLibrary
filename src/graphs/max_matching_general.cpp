/**
 * | Maximum matching | for general graphs using blossom-shrink algorithm
 */

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1001;
int n;                  // Number of vertices
bool edge[N][N];        // Adjacency matrix
int mate[N];            // Matched vertex (-1 => unmatched)
int label[N], base[N], prev1[N], prev2[N];
bool mark[N];

bool prepare(int v) {
    while(1) {
        mark[v] = !mark[v];
        if (mate[v] == -1) return mark[v];
        v = base[prev2[mate[v]]];
    }
}

int shrink(int v, int b1, int b2, queue<int> &Q) {
    while (mark[v]) {
        prev1[v] = b1; prev2[v] = b2;
        mark[mate[v]] = 1;
        Q.push(mate[v]);
        v = base[prev2[mate[v]]];
    }
    return v;
}

bool make_blos(int i, int j, int bi, int bj, queue<int> &Q) {
    if (label[i]!=1 || i==j) return 0;
    if (prepare(i), prepare(j)) return 1;
    int b = (shrink(i, bi, bj, Q), shrink(j, bj, bi, Q));
    for (int v=0; v<n; v++) if (mark[base[v]]) base[v] = b;
    return 0;
}

void rematch(int i, int j) {
    int next = mate[i];
    mate[i] = j;
    if (next==-1) return;
    mate[next] = -1;
    rematch(prev2[next], prev1[next]);
    rematch(prev1[next], prev2[next]);
}

bool augment() {
    queue<int> Q;
    for (int i=0; i<n; i++) {
        label[i] = mate[i]==-1;
        if (mate[i]==-1) Q.push(i);
        mark[i] = 0;
        base[i] = i;
    }
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int i=0; i<n; i++) if (edge[cur][i] && i!=mate[cur]) {
            if (!label[i]) {
                label[i] = -1;
                label[mate[i]] = 1;
                Q.push(mate[i]);
                prev1[i] = i; prev2[i] = cur;
            } else if (make_blos(base[i], base[cur], i, cur, Q)) {
                rematch(i, cur); rematch(cur, i);
                return 1;
            }
        }
    }
    return 0;
}

int max_matching() {
    fill_n(mate, n, -1);
    int res = 0;
    while (augment()) ++res;
    return res;
}


/**
 * Example usage
 */
int main() {
    ios::sync_with_stdio(0);
    n = 6;
    edge[0][1] = edge[1][0] = 1;
    edge[0][2] = edge[2][0] = 1;
    edge[0][3] = edge[3][0] = 1;
    edge[1][2] = edge[2][1] = 1;
    edge[1][4] = edge[4][1] = 1;
    edge[3][5] = edge[5][3] = 1;
    cout << "The cardinality of the maximum matching is " << max_matching() << "\n";
    return 0;
}

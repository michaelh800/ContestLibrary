/**
 * Suffix array O(n*logn) and LCP array O(n)
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

namespace suffix_array {
    string S;
    int N, K, gap;
    vector<int> sa, rank, tmp, lcp;

    bool cmp(int i, int j) {
        if (rank[i] != rank[j]) return rank[i] < rank[j];
        i += gap; j += gap;
        return (i < N && j < N) ? rank[i] < rank[j] : i > j;
    }

    void radix_pass(int g) {
        vector<int> b(N), c(K+1);
        for (int i=0; i<N; i++) (sa[i]+g < N) ? c[rank[sa[i]+g]]++ : c[0]++;
        for (int i=0, sum=0; i<=K; i++) {int t = c[i]; c[i] = sum; sum += t; }
        for (int i=0; i<N; i++)
            (sa[i]+g < N) ? b[c[rank[sa[i]+g]]++] = sa[i] : b[c[0]++] = sa[i];
        sa = b;
    }

    void build_sa() {
        N = S.length();
        sa = rank = tmp = lcp = vector<int>(N);
        for (int i=0; i<N; i++) {
            sa[i] = i, rank[i] = S[i], tmp[i] = 1;
            if (rank[i] > K) K = rank[i];
        }
        for (gap = 1;; gap *= 2) {
            radix_pass(gap); radix_pass(0);
            for (int i=0; i<N-1; i++) tmp[i+1] = tmp[i] + cmp(sa[i], sa[i+1]);
            for (int i=0; i<N; i++) rank[sa[i]] = tmp[i];
            K = tmp[N - 1]; if (K == N) break;
        }
        for (int &r : rank) r--;
    }

    void build_lcp() {
        for (int i=0, k=0; i<N; i++) if (rank[i] != N - 1) {
            for (int j = sa[rank[i]+1]; S[i+k] == S[j+k];) ++k;
            lcp[rank[i]] = k;
            if (k)--k;
        }
    }
}

/**
 * Example usage
 */
int main() {
    ios::sync_with_stdio(false);
    suffix_array::S = "abracadabra0AbRa4Cad14abra";
    suffix_array::build_sa();
    suffix_array::build_lcp();

    for (int &i : suffix_array::sa) {
        cout << i << " ";
    }
    cout << "\n";

    for (int &i : suffix_array::lcp) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

/**
 * Quick sort
 */

#include <bits/stdc++.h>
using namespace std;

template <class T>
int partition(vector<T> &arr, int lo, int hi) {
    int i = rand()%(hi-lo+1)+lo;
    swap(arr[i], arr[hi]);
    T p = arr[hi];
    int pi = lo;
    for (i=lo; i<hi; i++) {
        if (arr[i] < p) {
            swap(arr[i], arr[pi]);
            pi++;
        }
    }
    swap(arr[hi], arr[pi]);
    return pi;
}

template <class T>
void quick_sort(vector<T> &arr, int lo, int hi) {
    if (lo < hi) {
        int p = partition(arr, lo, hi);
        quick_sort(arr, lo, p-1);
        quick_sort(arr, p+1, hi);
    }
}

/**
 * Example usage
 */
int main() {
    vector<char> arr = { 'B', 'a', 't', 'm', 'a', 'n' };
    quick_sort(arr, 0, arr.size()-1);
    for (char c : arr) cout << c << " ";
    cout << "\n";
    return 0;
}

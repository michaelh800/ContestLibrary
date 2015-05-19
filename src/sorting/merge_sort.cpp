/**
 * Merge sort
 */

#include <bits/stdc++.h>
using namespace std;

template <class T>
void merge(vector<T> &arr, int lo, int mid, int hi) {
    int sz1 = mid - lo + 1;
    int sz2 = hi - mid;

    vector<T> left(sz1);
    vector<T> right(sz2);

    for (int i=0; i<sz1; i++) {
        left[i] = arr[lo + i];
    }
    for (int i=0; i<sz2; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = lo;

    while (i < sz1 || j < sz2) {
        if (i == sz1 || j == sz2) {
            if (i == sz1) {
                arr[k++] = right[j++];
            }
            else {
                arr[k++] = left[i++];
            }
        }
        else {
            if (left[i] < right[j]) {
                arr[k++] = left[i++];
            }
            else {
                arr[k++] = right[j++];
            }
        }
    }
}

template <class T>
void merge_sort(vector<T> &arr, int lo, int hi) {
    if (lo < hi) {
        int mid = (lo + hi) / 2;
        merge_sort(arr, lo, mid);
        merge_sort(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);
    }
}

/**
 * Example usage
 */
int main() {
    vector<char> arr = { 'B', 'a', 't', 'm', 'a', 'n' };
    merge_sort(arr, 0, arr.size()-1);
    for (char c : arr) cout << c << " ";
    cout << "\n";
    return 0;
}

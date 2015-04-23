/**
 * Quick sort
 */

#include <iostream>
#include <utility>
#include <vector>
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

template <class T>
void print_vector(vector<T> &arr) {
    for (const T &x : arr) {
        cout << x << " ";
    }
    cout << "\n";
}

/**
 * Example usage
 */
int main() {
    ios::sync_with_stdio(false);
    vector<int> t1 = { 9, 4, 6, 2, 1, 5, 8, 0, 3, 7 };
    vector<double> t2 = { 1.1, 4, 3.14159, -2.4, -1, 10 };
    vector<char> t3 = { 'B', 'a', 't', 'm', 'a', 'n' };

    quick_sort(t1, 0, t1.size()-1);
    quick_sort(t2, 0, t2.size()-1);
    quick_sort(t3, 0, t3.size()-1);

    print_vector(t1);
    print_vector(t2);
    print_vector(t3);
    return 0;
}

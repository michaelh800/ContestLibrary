#include <iostream>
#include <cstdio>
#include <vector>
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
                arr[k] = right[j];
                j++;
            }
            else {
                arr[k] = left[i];
                i++;
            }
        }
        else {
            if (left[i] < right[j]) {
                arr[k] = left[i];
                i++;
            }
            else {
                arr[k] = right[j];
                j++;
            }
        }
        k++;
    }
}

template <class T>
void mergeSort(vector<T> &arr, int lo, int hi) {
    if (lo < hi) {
        int mid = (lo + hi) / 2;
        mergeSort(arr, lo, mid);
        mergeSort(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);
    }
}

template <class T>
void printVector(vector<T> &arr) {
    cout << "{ ";
    for (auto const &x : arr) {
        cout << x << " ";
    }
    cout << "}" << endl;
}

template <class T>
void runTest(vector<T> arr) {
    printVector(arr);
    mergeSort(arr, 0, arr.size()-1);
    printVector(arr);
    cout << endl;
}

int main() {
    vector<int> t1 = { 9, 4, 6, 2, 1, 5, 8, 0, 3, 7 };
    vector<double> t2 = { 1.1, 4, 3.14159, -2.4, -1, 10 };
    vector<char> t3 = { 'B', 'a', 't', 'm', 'a', 'n' };

    runTest(t1);
    runTest(t2);
    runTest(t3);
    return 0;
}
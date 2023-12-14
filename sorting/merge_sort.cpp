/**
 * 
 * \file
 * \brief [merege sort 
 * algorithm](https://en.wikipedia.org/wiki/Merge_sort)
 *
 * \details
 * Merge Sort is an efficient, general purpose, 
 * comparison based sorting algorithm. 
 * Merge Sort is a divide and conquer algorithm
 *
 */

#include <algorithm>
#include <cassert>
#include <iostream>

namespace sorting {

template <typename T>
void merge(T* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    T *arr1 = new T[n1];
    T *arr2 = new T[n2];

    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[l + i];
    }
    
    for (int j = 0; j < n2; j++) {
        arr2[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 || j < n2) {
        if (j >= n2 || (i < n1 && arr1[i] <= arr2[j])) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    delete []arr1;
    delete []arr2;
}

template <typename T>
void process(T *arr, int l, int r) {
    if (l == r) {
        return;
    }

    int mid = l + ((r - l) >> 1);
    process(arr, l, mid);
    process(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

template <typename T>
void merge_sort(T *arr, int n) {
    if (arr == nullptr || n < 2) {
        return;
    }
    process(arr, 0, n-1);
}

}  // namespace sorting

/** Test Cases to test algorithm */
void test() {
    int arr1[9] = {100, -1, 30, 23, 24, 9, 34, 10, 28};
    std::cout << "Test 1... ";
    sorting::merge_sort(arr1, 9);
    assert(std::is_sorted(arr1, arr1 + 9));
    std::cout << "passed" << std::endl;

    float arr2[5] = {3.4, 10.1, -2.3, 6.8, 2.8};
    std::cout << "Test 2... ";
    sorting::merge_sort(arr2, 5);
    assert(std::is_sorted(arr2, arr2 + 5));
    std::cout << "passed" << std::endl;
}

int main() {
    test();
    return 0;
}
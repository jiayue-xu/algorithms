/**
 * \file
 * \brief [quick sort 
 * algorithm](https://en.wikipedia.org/wiki/Quicksort)
 *  
 * \details
 * Quick Sort is a divide and conquer algorithm.
 * It picks an element as pivot and partition the given array around the
 * picked pivot.
 */

#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <vector>

namespace sorting {

/**
 * {i | i ∈ [l, range0) && arr[i] < pivot}
 * {i | i ∈ [range0, range1] && arr[i] == pivot}
 * {i | i ∈ (range1, r] && arr[i] > pivot}
 */
template <typename T>
std::vector<int> partition(T *arr, int l, int r) {
    int less = l - 1;
    int more = r;
    
    while (l < more) {
        if (arr[l] < arr[r]) {
            std::swap(arr[l++], arr[++less]);
        } else if (arr[l] > arr[r]) {
            std::swap(arr[l], arr[--more]);
        } else {
            l++;
        }
    }

    std::swap(arr[r], arr[more]);    
    return {less + 1, more};
}

template <typename T>
void quick_sort(T *arr, int l, int r) {
    if (l < r) {
        int pivot = l + (std::rand() % (r - l + 1));
        std::swap(arr[pivot], arr[r]);
        std::vector<int> range = partition(arr, l, r);
        quick_sort(arr, l, range[0] - 1);
        quick_sort(arr, range[1] + 1, r);
    }
}

}  // namespace sorting

/** Test Cases to test algorithm */
void test() {
    int arr1[9] = {100, -1, 30, 23, 24, 9, 34, 10, 28};
    std::cout << "Test 1... ";
    sorting::quick_sort(arr1, 0, 8);
    assert(std::is_sorted(arr1, arr1 + 9));
    std::cout << "passed" << std::endl;

    float arr2[5] = {3.4, 10.1, -2.3, 6.8, 2.8};
    std::cout << "Test 2... ";
    sorting::quick_sort(arr2, 0, 4);
    assert(std::is_sorted(arr2, arr2 + 5));
    std::cout << "passed" << std::endl;
}

int main() {
    test();
    return 0;
}
/**
 *
 * \file
 * \brief [insertion sort 
 * algorithm](https://en.wikipedia.org/wiki/Insertion_sort)
 *
 * \details
 * Insertion sort is a simple sorting algorithm that builds the final
 * sorted array one at a time.
 * - Best case Time complexity O(n)
 * - Worst case Time complexity O(n^2)
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

namespace sorting {
/** \brief
 * Insertion Sort Function
 *
 * @tparam T type of array
 * @param [in,out] arr Array to be sorted
 * @param n Size of Array
 */
template <typename T>
void insertion_sort(T *arr, int n) {
    for (int i = 1; i < n; i++) {
        T temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

}  // namespace sorting

/** Test Cases to test algorithm */
void tests() {
    int arr1[9] = {100, -1, 30, 23, 24, 9, 34, 10, 28};
    std::cout << "Test 1... ";
    sorting::insertion_sort(arr1, 9);
    assert(std::is_sorted(arr1, arr1 + 9));
    std::cout << "passed" << std::endl;

    float arr2[5] = {3.4, 10.1, -2.3, 6.8, 2.8};
    std::cout << "Test 2... ";
    sorting::insertion_sort(arr2, 5);
    assert(std::is_sorted(arr2, arr2 + 5));
    std::cout << "passed" << std::endl;
}

int main() {
    tests();
    return 0;
}
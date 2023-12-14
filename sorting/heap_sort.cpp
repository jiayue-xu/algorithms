/**
 * 
 * \file
 * \brief [heap sort 
 * algorithm]()
 *
 * \details
 * 堆是一个完全二叉树，即可以表示成数组中从0坐标开始连续的一段
 *  假设当前节点坐标为i，则当前节点的
 *  左孩子坐标为2*i+1
 *  右孩子坐标为2*i+2
 *  父节点坐标为(i-1)/2
 * 堆的递归定义：
 *  大根堆：每一棵子树的最大值是子树的根节点
 *  小根堆：每一棵子树的最小值是子树的根节点
 */
#include <algorithm>
#include <cassert>
#include <iostream>

namespace sorting {

template <typename T>
void heap_insert(T *arr, int i) {
    while (arr[(i - 1) / 2] < arr[i]) {
        std::swap(arr[(i - 1) / 2], arr[i]);
        i = (i - 1) / 2;
    }
}

template <typename T>
void heapify(T *arr, int i, int n) {
    int l = i * 2 + 1;

    while (l < n) {
        int largest = l + 1 < n && arr[l + 1] > arr[l] 
                        ? l + 1 : l;
        largest = arr[largest] > arr[i] ? largest : i;

        if (largest == i) {
            break;
        }

        std::swap(arr[largest], arr[i]);
        i = largest;
        l = largest * 2 + 1;
    }
}

// 基于大根堆的排序
template <typename T>
void heap_sort(T *arr, int n) {
    for (int i = 0; i < n; i++) {
        heap_insert(arr, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

// 基于大根堆的排序
template <typename T>
void heap_sort1(T *arr, int n) {
    for (int i = n - 1; i >= 0; i--) {
        heapify(arr, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

}  // namespace sorting

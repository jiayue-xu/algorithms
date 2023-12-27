/**
 *
 * \brief [Longest increasing 
 * subsequence](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/?ref=header_search)
 * 
 */

#include <cassert>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * lis[i]表示以arr[i]为结尾且最长的递增序列的长度：
 *  - 1 + max{lis[j]} where arr[j] < arr[i] && 0 < j < i
 *  - 1, if no such j exists.
*/
int lengthOfLIS(std::vector<int>& arr) {
    std::vector<int> lis(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && 1 + lis[j] > lis[i]) {
                lis[i] = 1 + lis[j];
            }
        }
    }
    return *std::max_element(lis.begin(), lis.end());
}

void test() {
    std::vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
    assert(lengthOfLIS(arr) == 5);

    std::cout << "passed" << std::endl;
}

int main() {
    test();
}
/**
 *
 * \file
 * \brief [KMP Algorithm 
 *  for Pattern Searching](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)
 *
 * \details
 *
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

namespace search {

std::vector<int> get_lps_array(const std::string &pattern) {
    int m = pattern.size();
    std::vector<int> res(m + 1, 0);

    int i = 1, len = 0;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            res[i++] = ++len;
        } else {
            if (len == 0) {
                res[i++] = 0;
            } else {
                len = res[len-1];
            }
        }
    }
    return res;
}

std::vector<int> kmp(const std::string &text, const std::string &pattern) {
    std::vector<int> res;
    std::vector<int> lps = get_lps_array(pattern);

    int n = text.size(), m = pattern.size();
    int i = 0, j = 0;
    
    while (n - i >= m - j) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                res.push_back(i - m);
                j = lps[j - 1];
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }  
        }
    }

    return res;
}

}  // namespace search

void tests() {
    std::string text = "ABABDABACDABABCABABABABCABAB";
    std::string pattern = "ABABCABAB";

    std::vector<int> pos = search::kmp(text, pattern);

    for (auto p : pos) {
        std::cout << p << std::endl;
    }

    text = "aaaaaaaa";
    pattern = "aaa";
    pos = search::kmp(text, pattern);

    for (auto p : pos) {
        std::cout << p << std::endl;
    }

    text = "aaaaakaaa";
    pattern = "aaa";
    pos = search::kmp(text, pattern);

    for (auto p : pos) {
        std::cout << p << std::endl;
    }
}

int main() {
    tests();
    return 0;
}
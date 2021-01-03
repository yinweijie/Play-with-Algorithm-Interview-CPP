#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/description/
//
// 计数排序
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int R = 3;

        vector<int> cnt(R, 0);
        for(auto num : nums) {
            cnt[num]++;
        }

        vector<int> index(R + 1, 0);
        for(int i = 0; i + 1 < index.size(); i++) {
            index[i + 1] = index[i] + cnt[i];
        }

        for(int i = 0; i + 1 < index.size(); i++) {
            for(int j = index[i]; j < index[i + 1]; j++) {
                nums[j] = i;
            }
        }
    }
};
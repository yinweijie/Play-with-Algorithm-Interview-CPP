#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/description/
//
// 三路快速排序的思想
// 对整个数组只遍历了一遍
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1;          // [0...zero] == 0
        int two = nums.size();  // [two...n-1] == 2

        for(int i = 0; i < two; ) {
            if(nums[i] == 1) {
                i++;
            } else if (nums[i] == 2) {
                two--;
                swap(nums[i], nums[two]);
            } else {
                assert(nums[i] == 0);
                zero++;
                swap(nums[i], nums[zero]);
                i++;
            }
        }
    }
};
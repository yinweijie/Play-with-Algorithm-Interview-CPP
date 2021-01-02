#include <iostream>
#include <vector>

using namespace std;

// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
//
// 原地(in place)解决该问题
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0; // [0, k)之间为非0元素

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }

        for(int i = k; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
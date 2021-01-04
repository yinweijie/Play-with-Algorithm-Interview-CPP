#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/description/
//
// 优化暴力解
// 时间复杂度: O(n^2)
// 空间复杂度: O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // sum[i]为[0...i)之间的和
        // 因此[l...r]之间的和为sum[r + 1] - sum[l]
        vector<int> sum(nums.size() + 1, 0);
        for(int i = 1; i < sum.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        int res = nums.size() + 1;
        for(int l = 0; l < nums.size(); l++) {
            for(int r = l; r < nums.size(); r++) {
                if(sum[r + 1] - sum[l] >= s) {
                    res = std::min(r - l + 1, res);
                }
            }
        }

        if(res == nums.size() + 1) {
            res = 0;
        }

        return res;
    }
};
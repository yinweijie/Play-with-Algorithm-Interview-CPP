#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>

using namespace std;

/// 416. Partition Equal Subset Sum
/// https://leetcode.com/problems/partition-equal-subset-sum/description/
/// 动态规划
/// 时间复杂度: O(len(nums) * O(sum(nums)))
/// 空间复杂度: O(len(nums) * O(sum(nums)))
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;

        int n = nums.size();
        int C = sum / 2;

        vector<bool> memo(C + 1, false);        
        for(int i = 0; i <= C; i++) {
            memo[i] = (nums[0] == i);
        }

        for(int i = 1; i < n; i++) {
            for(int j = C; j >= nums[i]; j--) {
                memo[j] = memo[j] || memo[j - nums[i]];
            }
        }

        return memo[C];
    }
};
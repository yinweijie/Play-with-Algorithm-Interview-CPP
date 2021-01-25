#include <iostream>
#include <vector>

using namespace std;

/// 198. House Robber
/// https://leetcode.com/problems/house-robber/description/
/// 动态规划, 改变状态定义
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0) return 0;

        vector<int> memo(n, 0);

        // memo[i] 表示考虑抢劫 nums[0...i] 所能获得的最大收益
        memo[0] = nums[0];
        for(int i = 1; i < n; i++) {
            int res = 0;
            for(int j = 0; j <= i; j++) {
                res = max(res, nums[j] + (j - 2 < 0 ? 0 : memo[j - 2]));
            }
            memo[i] = res;
        }

        return memo[n - 1];
    }
};
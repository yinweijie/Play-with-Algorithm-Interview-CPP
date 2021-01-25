#include <iostream>
#include <vector>

using namespace std;

/// 198. House Robber
/// https://leetcode.com/problems/house-robber/description/
/// 动态规划
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0) return 0;

        // memo[i] 表示考虑抢劫 nums[i...n) 所能获得的最大收益
        vector<int> memo(n, 0);
        memo[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            int res = 0;
            for(int j = i; j < n; j++) {
                res = max(res, nums[j] + (j + 2 >= n ? 0 : memo[j + 2]));
            }
            memo[i] = res;
        }

        return memo[0];
    }
};
#include <iostream>
#include <vector>

using namespace std;

/// 198. House Robber
/// https://leetcode.com/problems/house-robber/description/
/// 记忆化搜索, 改变状态定义
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)
class Solution {
private:
    vector<int> memo;

    int tryRob(vector<int>& nums, int index) {
        int n = nums.size();
        if(index < 0) return 0;

        if(memo[index] != -1) {
            return memo[index];
        }

        int res = 0;
        for(int i = 0; i <= index; i++) {
            res = max(res, nums[i] + tryRob(nums, i - 2));
        }
        memo[index] = res;

        return res;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, -1);

        return tryRob(nums, n - 1);
    }
};
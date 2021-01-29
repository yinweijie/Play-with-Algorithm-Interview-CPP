#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/// 300. Longest Increasing Subsequence
/// https://leetcode.com/problems/longest-increasing-subsequence/description/
/// 记忆化搜索
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        vector<int> memo(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    memo[i] = max(memo[i], memo[j] + 1);
                }
            }
        }

        int res = *max_element(memo.begin(), memo.end());

        return res;
    }
};
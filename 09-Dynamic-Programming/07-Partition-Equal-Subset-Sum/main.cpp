#include <iostream>
#include <vector>
#include <cassert>
#include <functional>
#include <numeric>

using namespace std;

/// 416. Partition Equal Subset Sum
/// https://leetcode.com/problems/partition-equal-subset-sum/description/
/// 记忆化搜索
/// 时间复杂度: O(len(nums) * O(sum(nums)))
/// 空间复杂度: O(len(nums) * O(sum(nums)))
class Solution {
private:
    // memo[i][c] 表示使用索引为[0...i]的这些元素,是否可以完全填充一个容量为c的背包
    // -1 表示为未计算; 0 表示不可以填充; 1 表示可以填充
    vector<vector<int>> memo;

    // 使用nums[0...index], 是否可以完全填充一个容量为sum的背包
    bool tryPartition(vector<int>& nums, int index, int sum) {
        if(sum == 0) return true;

        if(index < 0 || sum < 0) return false;

        if(memo[index][sum] != -1) {
            return memo[index][sum] == 1;
        }

        memo[index][sum] = tryPartition(nums, index - 1, sum) ||
            tryPartition(nums, index - 1, sum - nums[index]);

        return memo[index][sum] == 1;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) {
            return false;
        }
        
        int n = nums.size();
        memo = vector<vector<int>>(n, vector<int>(sum / 2 + 1, -1));

        return tryPartition(nums, n - 1, sum / 2);
    }
};
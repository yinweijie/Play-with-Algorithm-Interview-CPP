#include <iostream>
#include <vector>

using namespace std;

/// 70. Climbing Stairs
/// https://leetcode.com/problems/climbing-stairs/description/
/// 记忆化搜索
/// 时间复杂度: O(n)
/// 空间复杂度: O(n)
class Solution {
private:
    vector<int> memo;

    int calWays(int n) {
        if(n == 0 || n == 1) {
            return 1;
        }

        if(memo[n] == -1) {
            memo[n] = calWays(n - 1) + calWays(n - 2);
        }

        return memo[n];
    }
public:
    int climbStairs(int n) {
        memo.assign(n + 1, -1);

        return calWays(n);
    }
};
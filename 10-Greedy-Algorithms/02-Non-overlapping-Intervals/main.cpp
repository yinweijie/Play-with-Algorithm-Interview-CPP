#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// 435. Non-overlapping Intervals
/// https://leetcode.com/problems/non-overlapping-intervals/description/
/// 动态规划
/// 时间复杂度: O(n^2)
/// 空间复杂度: O(n)
bool compare(vector<int>& interval1, vector<int>& interval2) {
    if(interval1[0] != interval2[0]) {
        return interval1[0] < interval2[0];
    }
    return interval1[1] < interval2[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;

        sort(intervals.begin(), intervals.end(), compare);
        vector<int> memo(intervals.size(), 1);

        for(int i = 1; i < intervals.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(intervals[i][0] >= intervals[j][1]) {
                    memo[i] = max(memo[i], memo[j] + 1);
                }
            }
        }

        int res = *max_element(memo.begin(), memo.end());

        return intervals.size() - res;
    }
};

int main() {
    Solution();
    return 0;
}
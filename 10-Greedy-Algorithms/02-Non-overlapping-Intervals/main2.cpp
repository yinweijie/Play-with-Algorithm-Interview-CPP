#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// 435. Non-overlapping Intervals
/// https://leetcode.com/problems/non-overlapping-intervals/description/
/// 贪心算法
/// 时间复杂度: O(n)
/// 空间复杂度: O(n)

bool compare(vector<int>& interval1, vector<int>& interval2) {
    if(interval1[1] != interval2[1]) {
        return interval1[1] < interval2[1];
    }
    return interval1[0] < interval2[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;

        sort(intervals.begin(), intervals.end(), compare);

        int res = 1;
        int pre = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= intervals[pre][1]) {
                res++;
                pre = i;
            }
        }

        return intervals.size() - res;
    }
};
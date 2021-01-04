#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/description/
//
// 滑动窗口的思路
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = -1;
        int sum = 0; // sum表示[l...r]之间的和
        int res = nums.size() + 1;

        while(l < nums.size()) {
            if(r + 1 < nums.size() && sum < s) {
                sum += nums[++r];
            } else {
                sum -= nums[l++];
            }

            if(sum >= s) {
                res = std::min(res, r - l + 1);
            }
        }

        if(res == nums.size() + 1) {
            res = 0;
        }

        return res;
    }
};

int main()
{
    vector<int> nums {2,3,1,2,4,3};
    cout << Solution().minSubArrayLen(7, nums) << endl;
    return 0;
}
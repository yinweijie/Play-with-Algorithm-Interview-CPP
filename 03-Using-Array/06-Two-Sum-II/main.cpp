#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
//
// 二分搜索法
// 时间复杂度: O(nlogn)
// 空间复杂度: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size() - 1; i++) {
            int res = binarySearch(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
            if(res != -1) {
                return vector<int> {i + 1, res + 1};
            }
        }

        return vector<int>();
    }

private:
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] == target) {
                return mid;
            }

            if(nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }
};
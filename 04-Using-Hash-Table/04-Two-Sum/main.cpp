#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

// 1. Two Sum
// https://leetcode.com/problems/two-sum/description/
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if(record.find(complement) != record.end()) {
                return vector<int> {record[complement], i};
            }

            record[nums[i]] = i;
        }

        return vector<int>();
    }
};
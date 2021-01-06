#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <stdexcept>
#include <cmath>

using namespace std;

// 220. Contains Duplicate III
// https://leetcode.com/problems/contains-duplicate-iii/description/
// 时间复杂度: O(nlogk)
// 空间复杂度: O(k)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> record;

        for(int i = 0; i < nums.size(); i++) {
            auto it = record.lower_bound(static_cast<long long>(nums[i]) - static_cast<long long>(t));
            if(it != record.end() && *it <= static_cast<long long>(nums[i]) + static_cast<long long>(t)) {
                return true;
            }

            record.insert(nums[i]);

            if(record.size() == k + 1) {
                record.erase(nums[i - k]);
            }
        }

        return false;
    }
};
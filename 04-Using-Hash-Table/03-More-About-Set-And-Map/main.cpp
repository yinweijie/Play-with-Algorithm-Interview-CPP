#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/description/
// 时间复杂度: O(nlogn)
// 空间复杂度: O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> record;
        for(auto num : nums1) {
            record.insert(num);
        }

        unordered_set<int> resultSet;
        for(auto num : nums2) {
            if(record.find(num) != record.end()) {
                resultSet.insert(num);
            }
        }

        return vector<int>(resultSet.begin(), resultSet.end());
    }
};
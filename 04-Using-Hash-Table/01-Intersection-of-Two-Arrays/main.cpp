#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/description/
// 时间复杂度: O(nlogn)
// 空间复杂度: O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record;
        for(auto num : nums1) {
            record.insert(num);
        }

        set<int> resultSet;
        for(auto num : nums2) {
            if(record.find(num) != record.end()) {
                resultSet.insert(num);
            }
        }

        return vector<int>(resultSet.begin(), resultSet.end());
    }
};
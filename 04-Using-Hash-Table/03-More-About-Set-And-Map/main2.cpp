#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
// 时间复杂度: O(nlogn)
// 空间复杂度: O(n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> record;

        for(auto num : nums1) {
            record[num]++;
        }

        vector<int> res;
        for(auto num : nums2) {
            if(record.find(num) != record.end()) {
                res.emplace_back(num);
                record[num]--;

                if(record[num] == 0) {
                    record.erase(num);
                }
            }
        }

        return res;
    }
};
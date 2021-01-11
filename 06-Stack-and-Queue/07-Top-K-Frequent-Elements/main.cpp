#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>

using namespace std;

// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/description/
// 时间复杂度: O(nlogk)
// 空间复杂度: O(n + k)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(auto num : nums) {
            freq[num]++;
        }

        // pair(频率, 元素)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto[num, freq_e] : freq) {
            if(pq.size() == k) {
                if(freq_e > pq.top().first) {
                    pq.pop();
                    pq.emplace(make_pair(freq_e, num));
                }
            } else {
                pq.emplace(make_pair(freq_e, num));
            }
        }

        vector<int> ret;
        for(int i = 0; i < k; i++) {
            ret.emplace_back(pq.top().second);
            pq.pop();
        }

        return ret;
    }
};
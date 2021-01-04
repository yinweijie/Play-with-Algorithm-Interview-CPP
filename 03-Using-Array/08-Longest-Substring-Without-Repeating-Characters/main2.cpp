#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//
// 滑动窗口
// 时间复杂度: O(len(s))
// 空间复杂度: O(len(charset))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = -1;
        int res = 0;
        vector<int> freq(256);

        // 因为需要找的是最大区间，当r + 1 == s.size()的时候，r此时已经在最右边
        // 此时无法通过滑动l或r，获得更长的区间了
        while(r + 1 < s.size()) {
            if(freq[s[r + 1]] == 0) {
                r++;
                freq[s[r]]++;
            } else {
                freq[s[l]]--;
                l++;
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};
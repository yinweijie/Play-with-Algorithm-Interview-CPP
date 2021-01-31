#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// 455. Assign Cookies
/// https://leetcode.com/problems/assign-cookies/description/
/// 先尝试满足最贪心的小朋友
/// 时间复杂度: O(nlogn)
/// 空间复杂度: O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int gi = 0, si = 0;
        int res = 0;
        while(gi < g.size() && si < s.size()) {
            if(g[gi] <= s[si]) {
                res++;
                gi++;
                si++;
            } else {
                gi++;
            }
        }

        return res;
    }
};
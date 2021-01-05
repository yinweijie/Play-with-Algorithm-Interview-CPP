#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <stdexcept>
#include <cmath>

using namespace std;

// 447. Number of Boomerangs
// https://leetcode.com/problems/number-of-boomerangs/description/
// 时间复杂度: O(n^2)
// 空间复杂度: O(n)
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;

        for(int i = 0; i < points.size(); i++) {
            unordered_map<int, int> record;
            for(int j = 0; j < points.size(); j++) {
                if(i != j) {
                    int dist2 = cal_dist2(points[i], points[j]);
                    record[dist2]++;
                }
            }

            for(auto[_, value] : record) {
                if(value >= 2) {
                    res += value * (value - 1);
                }
            }
        }

        return res;
    }

private:
    int cal_dist2(vector<int>& pa, vector<int>& pb) {
        return std::pow(pa[0] - pb[0], 2) + std::pow(pa[1] - pb[1], 2);
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/description/
// 时间复杂度: O(n^2)
// 空间复杂度: O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> record1;
        unordered_map<int, int> record2;

        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                record1[A[i] + B[j]]++;
            }
        }

        for(int i = 0; i < C.size(); i++) {
            for(int j = 0; j < D.size(); j++) {
                record2[C[i] + D[j]]++;
            }
        }

        int res = 0;
        for(auto[key, value] : record1) {
            if(record2.find(-key) != record2.end()) {
                res += value * record2[-key];
            }
        }

        return res;
    }
};
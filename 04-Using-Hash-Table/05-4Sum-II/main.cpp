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
        unordered_map<int, int> record;

        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                record[A[i] + B[j]]++;
            }
        }

        int res = 0;
        for(int i = 0; i < C.size(); i++) {
            for(int j = 0; j < D.size(); j++) {
                res += record[-C[i] - D[j]];
            }
        }

        return res;
    }
};
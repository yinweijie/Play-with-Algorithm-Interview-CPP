#include <iostream>
#include <vector>

using namespace std;

// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/
// 时间复杂度: O(n)
// 空间复杂度: O(n)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZeroes;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nonZeroes.emplace_back(nums[i]);
            }
        }

        for(int i = 0; i < nonZeroes.size(); i++) {
            nums[i] = nonZeroes[i];
        }

        for(int i = nonZeroes.size(); i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
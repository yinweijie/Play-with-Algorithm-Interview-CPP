#include <iostream>
#include <vector>
using namespace std;

/// 46. Permutations
/// https://leetcode.com/problems/permutations/description/
/// 时间复杂度: O(n^n)
/// 空间复杂度: O(n)
class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;

    // p中保存了一个有index-1个元素的排列。
    // 向这个排列的末尾添加第index个元素, 获得一个有index个元素的排列
    void generatePermutations(const vector<int>& nums, int index, vector<int>& p) {
        if(index == nums.size()) {
            res.emplace_back(p);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(!used[i]) {
                used[i] = true;
                p.emplace_back(nums[i]);
                generatePermutations(nums, index + 1, p);
                used[i] = false;
                p.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return res;

        vector<int> p;
        used.assign(nums.size(), false);
        generatePermutations(nums, 0, p);

        return res;
    }
};

#include <iostream>
#include <vector>

using namespace std;

/// 77. Combinations
/// https://leetcode.com/problems/combinations/description/
/// 时间复杂度: O(n^k)
/// 空间复杂度: O(k)
class Solution {
private:
    vector<vector<int>> res;

    // 求解C(n,k), 当前已经找到的组合存储在c中, 需要从start开始搜索新的元素
    void generateCombinations(int n, int k, int start, vector<int>& c) {
        if(c.size() == k) {
            res.emplace_back(c);
            return;
        }

        for(int i = start; i <= n; i++) {
            c.emplace_back(i);
            generateCombinations(n, k, i + 1, c);
            c.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        if(n <= 0 || k <= 0 || k > n) return res;

        vector<int> c;
        generateCombinations(n, k, 1, c);

        return res;
    }
};

int main()
{
    Solution().combine(2, 2);
    return 0;
}
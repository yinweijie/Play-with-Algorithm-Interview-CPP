#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/description/
// 使用visited数组,记录每一个入队元素
//
// 时间复杂度: O(n)
// 空间复杂度: O(n)
class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> q;
        vector<bool> visited(n + 1);
        q.emplace(make_pair(n, 0)); // 用于保存层序遍历的图节点，pair(num, step)表示从n到num，需要走step步
        visited[n] = true; 

        while(!q.empty()) { // 无权图的层序遍历，可以得到最小路径
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            if(num == 0) return step;

            for(int i = 1; num - i*i >= 0; i++) { // 节点num周围的值，放入队列中，用于层序遍历
                if(!visited[num - i*i]) {
                    q.emplace(make_pair(num - i*i, step + 1));
                    visited[num - i*i] = true;
                }
            }
        }

        return -1;
    }
};
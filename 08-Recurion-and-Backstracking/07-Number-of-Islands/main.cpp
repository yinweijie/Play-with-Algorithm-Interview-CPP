#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// 200. Number of Islands
/// https://leetcode.com/problems/number-of-islands/description/
/// 时间复杂度: O(n*m)
/// 空间复杂度: O(n*m)
class Solution {
private:
    int direction[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    int m, n;
    vector<vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x <= m - 1 && y >=0 && y <= n - 1;
    }

    // 从grid[x][y]的位置开始,进行floodfill
    // 保证(x,y)合法,且grid[x][y]是没有被访问过的陆地
    void dfs(vector<vector<char>>& grid, int x, int y) {
        visited[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int newX = x + direction[i][0];
            int newY = y + direction[i][1];

            if(inArea(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '1') {
                dfs(grid, newX, newY);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        assert(m > 0);
        n = grid[0].size();
        assert(n > 0);

        visited.assign(m, vector<bool>(n, false));

        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }
};
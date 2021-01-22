#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// 51. N-Queens
/// https://leetcode.com/problems/n-queens/description/
/// 时间复杂度: O(n^n)
/// 空间复杂度: O(n)
class Solution {
private:
    vector<bool> col, diag1, diag2;
    vector<vector<string>> res;

    // 尝试在一个n皇后问题中, 摆放第index行的皇后位置
    void putQueen(int n, int index, vector<int>& row) {
        if(index == n) {
            res.emplace_back(generateBorad(n, row));
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!col[i] && !diag1[index + i] && !diag2[index - i + n - 1]) {
                col[i] = true;
                diag1[index + i] = true;
                diag2[index - i + n - 1] = true;
                row.emplace_back(i);

                putQueen(n, index + 1, row);

                col[i] = false;
                diag1[index + i] = false;
                diag2[index - i + n - 1] = false;
                row.pop_back();
            }
        }
    }

    vector<string> generateBorad(int n, vector<int>& row) {
        vector<string> board(n, string(n, '.'));

        for(int i = 0; i < n; i++) {
            board[i][row[i]] = 'Q';
        }

        return board;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        col.assign(n, false);
        diag1.assign(2*n - 1, false);
        diag2.assign(2*n - 1, false);

        vector<int> row;
        putQueen(n, 0, row);

        return res;
    }
};
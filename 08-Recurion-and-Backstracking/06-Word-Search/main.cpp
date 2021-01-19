#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// 79. Word Search
/// Source : https://leetcode.com/problems/word-search/description/
///
/// 回溯法
/// 时间复杂度: O(m*n*m*n)
/// 空间复杂度: O(m*n)
class Solution {
private:
    int m, n;
    int direction[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    vector<vector<bool>> visited;

    bool inArea(int X, int Y) {
        return X >= 0 && X < m && Y >= 0 && Y < n;
    }

    // 从board[startx][starty]开始, 寻找word[index...word.size())
    bool searchWord(vector<vector<char>>& board, string word, int index, int startX, int startY) {
        if(index == word.size() - 1) {
            return (board[startX][startY] == word[index]);
        }

        if(board[startX][startY] == word[index]) {
            visited[startX][startY] = true;

            for(int i = 0; i < 4; i++) {
                int newX = startX + direction[i][0];
                int newY = startY + direction[i][1];
                if(inArea(newX, newY) && !visited[newX][newY] &&
                        searchWord(board, word, index + 1, newX, newY)) {
                    return true;
                }
            }

            visited[startX][startY] = false;
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        assert(m > 0);
        n = board[0].size();
        assert(n > 0);

        visited.assign(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(searchWord(board, word, 0, i, j)) return true;
            }
        }

        return false;
    }
};
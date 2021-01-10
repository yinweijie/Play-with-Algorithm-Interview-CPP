#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

/// 102. Binary Tree Level Order Traversal
/// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
/// 二叉树的层序遍历
/// 时间复杂度: O(n), n为树的节点个数
/// 空间复杂度: O(n)
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        if(root == nullptr) return ret;

        queue<pair<TreeNode*, int>> q;
        q.emplace(make_pair(root, 0));
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level == ret.size()) {
                ret.emplace_back(vector<int>());
            }

            ret[level].emplace_back(node->val);

            if(node->left) {
                q.emplace(make_pair(node->left, level + 1));
            }
            if(node->right) {
                q.emplace(make_pair(node->right, level + 1));
            }
        }

        return ret;
    }
};
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/// 257. Binary Tree Paths
/// https://leetcode.com/problems/binary-tree-paths/description/
/// 时间复杂度: O(n), n为树中的节点个数
/// 空间复杂度: O(h), h为树的高度
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;

        if(root == nullptr) return res;

        if(root->left == nullptr && root->right == nullptr) {
            res.emplace_back(to_string(root->val));
            return res;
        }

        vector<string> leftStr = binaryTreePaths(root->left);
        for(int i = 0; i < leftStr.size(); i++) {
            res.emplace_back(to_string(root->val) + "->" + leftStr[i]);
        }

        vector<string> rightStr = binaryTreePaths(root->right);
        for(int i = 0; i < rightStr.size(); i++) {
            res.emplace_back(to_string(root->val) + "->" + rightStr[i]);
        }

        return res;
    }
};
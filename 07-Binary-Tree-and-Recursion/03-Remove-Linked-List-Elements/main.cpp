#include <iostream>

using namespace std;
/// 112. Path Sum
/// https://leetcode.com/problems/path-sum/description/
/// 时间复杂度: O(n), n为树的节点个数
/// 空间复杂度: O(h), h为树的高度
/**
Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;

        if(root->left == nullptr && root->right == nullptr) {
            return sum == root->val;
        }

        return hasPathSum(root->left, sum - root->val) ||
                hasPathSum(root->right, sum - root->val);
    }
};
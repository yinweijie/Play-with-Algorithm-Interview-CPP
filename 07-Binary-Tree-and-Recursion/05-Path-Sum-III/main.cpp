#include <iostream>

using namespace std;

/// 437. Path Sum III
/// https://leetcode.com/problems/path-sum-iii/description/
/// 时间复杂度: O(n), n为树的节点个数
/// 空间复杂度: O(h), h为树的高度
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    // 在以root为根节点的二叉树中,寻找和为sum的路径,返回这样的路径个数
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;

        return findPath(root, sum) +
                pathSum(root->left, sum) +
                pathSum(root->right, sum);
    }

private:
    // 在以node为根节点的二叉树中,寻找包含node的路径,和为sum
    // 返回这样的路径个数
    int findPath(TreeNode* node, int sum) {
        if(node == nullptr) return 0;

        int res = 0;
        if(node->val == sum) {
            res += 1;
        }

        res += findPath(node->left, sum - node->val);
        res += findPath(node->right, sum - node->val);

        return res;
    }
};
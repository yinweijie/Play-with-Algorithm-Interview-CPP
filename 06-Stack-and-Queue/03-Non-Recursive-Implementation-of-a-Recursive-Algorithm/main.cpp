#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

/// 144. Binary Tree Preorder Traversal
/// https://leetcode.com/problems/binary-tree-preorder-traversal/description/
/// 非递归的二叉树的前序遍历
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
private:
    struct Command {
        string name; // print, go
        TreeNode* node;

        Command(const string& name_, TreeNode* node_) : name(name_), node(node_) { }
    };

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<Command> stk;

        if(root == nullptr) return ret;

        stk.push(Command("go", root));
        while(!stk.empty()) {
            Command cmd = stk.top();
            stk.pop();

            if(cmd.name == "print") {
                ret.emplace_back(cmd.node->val);
            } else {
                assert(cmd.name == "go");

                if(cmd.node->right)
                    stk.push(Command("go", cmd.node->right));
                if(cmd.node->left)
                    stk.push(Command("go", cmd.node->left));
                stk.push(Command("print", cmd.node));
            }
        }

        return ret;
    }
};
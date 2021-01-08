// 237. Delete Node in a Linked List
// https://leetcode.com/problems/delete-node-in-a-linked-list/description/
// 时间复杂度: O(1)
// 空间复杂度: O(1)
#include <iostream>
#include <cassert>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == nullptr) {
            return;
        }

        node->val = node->next->val;
        
        ListNode* toDel = node->next;
        node->next = toDel->next;
        delete toDel;
    }
};
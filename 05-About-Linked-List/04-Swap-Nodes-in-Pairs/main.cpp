// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/description/
// 时间复杂度: O(n)
// 空间复杂度: O(1)
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode* p = dummyNode;
        while(p->next && p->next->next) {
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;

            node1->next = node2->next;
            node2->next = node1;
            p->next = node2;

            p = node1;
        }

        ListNode* retNode = dummyNode->next;
        delete dummyNode;

        return retNode;
    }
};
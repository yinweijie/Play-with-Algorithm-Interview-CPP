// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
//
// 使用双指针, 对链表只遍历了一遍
// 时间复杂度: O(n)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        ListNode* q = dummyHead;
        for(int i = 0; i < n + 1; i++) {
            assert(q != nullptr);
            q = q->next;
        }

        while(q != nullptr) {
            p = p->next;
            q = q->next;
        }

        ListNode* toDel = p->next;
        p->next = toDel->next;
        delete toDel;

        ListNode* retNode = dummyHead->next;
        delete dummyHead;

        return retNode;
    }
};
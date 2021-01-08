// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/description/
// 使用虚拟头结点
// 时间复杂度: O(n)
// 空间复杂度: O(1)
#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode* cur = dummyNode;
        while(cur->next != nullptr) {
            if(cur->next->val == val) {
                ListNode* toDel = cur->next;
                cur->next = toDel->next;
                delete toDel;
            } else {
                cur = cur->next;
            }
        }

        ListNode* retNode = dummyNode->next;
        delete dummyNode;

        return retNode;
    }
};
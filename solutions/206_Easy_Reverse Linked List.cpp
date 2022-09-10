/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode *prev = nullptr;
        ListNode *nxt = head -> next;
        
        while (nxt != nullptr) {
            // Reverse cur head to prev
            head -> next = prev;
            prev = head;
            head = nxt;
            nxt = nxt -> next;
        }
        
        head -> next = prev;
        
        return head;
    }
};
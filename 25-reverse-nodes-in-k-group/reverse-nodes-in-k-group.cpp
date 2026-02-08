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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* curr = head;
        ListNode* prevTail = NULL;
        ListNode* newHead = NULL;

        while (curr!=NULL) {
            // Check if k nodes exist
            ListNode* check = curr;
            int count = 0;
            while (check && count < k) {
                check = check->next;
                count++;
            }
            if (count < k) break;

            // Reverse k nodes
            ListNode* prev = NULL;
            ListNode* temp = curr;
            for (int i = 0; i < k; i++) {
                ListNode* next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
            }

            // Set new head
            if (!newHead) newHead = prev;

            // Connect previous group
            if (prevTail) prevTail->next = prev;

            // Move prevTail and curr
            prevTail = curr;
            curr = temp;
        }

        // Connect remaining nodes
        if (prevTail) prevTail->next = curr;

        return newHead ? newHead : head;
    }
};
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessDummy = new ListNode();
        ListNode* greaterDummy = new ListNode();

        ListNode* less = lessDummy;
        ListNode* greater = greaterDummy;

        ListNode* curr = head;
        while(curr!=NULL){
           ListNode* next = curr->next;
            if(curr->val < x){
                less->next = curr;
                less = curr;
            }
            else{
                greater->next = curr;
                greater = curr;
            }
            curr=next;
            greater->next = NULL;
            less->next = greaterDummy->next;
        }
        return lessDummy->next;
    }
};
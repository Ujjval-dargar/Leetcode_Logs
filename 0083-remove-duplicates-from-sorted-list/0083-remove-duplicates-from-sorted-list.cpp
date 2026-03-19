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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != NULL){
            ListNode* nxt = curr->next;
            while (nxt != NULL && nxt->val == curr->val){
                nxt = nxt->next;
            }
            curr->next = nxt;
            curr = nxt;
        }
        return head;
    }
};
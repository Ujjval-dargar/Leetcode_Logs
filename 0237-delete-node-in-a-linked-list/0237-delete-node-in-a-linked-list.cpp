/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* nxt = curr->next;

        while (nxt->next!=NULL){
            curr->val=nxt->val;
            curr=curr->next;
            nxt=nxt->next;
        }

        curr->val=nxt->val;
        curr->next=NULL;

    }
};
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

    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseListNode(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;

        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        ListNode* mid = findMiddle(curr);
        ListNode* lst = reverseListNode(mid);

        while (curr != NULL && lst != NULL){
            if (curr->val != lst->val) return false;
            curr = curr->next;
            lst = lst->next;
        }

        return true;
    }
};
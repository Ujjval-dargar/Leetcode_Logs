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
    int length(ListNode* head) {
        int ans = 0;
        while (head != nullptr) {
            ans++;
            head = head->next;
        }
        return ans;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s = length(head);
        n = s - n + 1;

        if (n == 1) {
            return head->next;
        }

        int i = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != nullptr) {
            i++;
            if (i == n) {
                prev->next=curr->next;
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
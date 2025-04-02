
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
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* evenHead = head;
        ListNode* oddHead = head->next;

        ListNode* evenCurr = evenHead;
        ListNode* oddCurr = oddHead;
        ListNode* curr = head;

        int i = 0;

        while (curr != nullptr) {
            if (curr == evenHead || curr == oddHead) {
                curr = curr->next;
                i++;
                continue;
            }

            ListNode* next = curr->next;
            if (i % 2 == 0) {
                evenCurr->next = curr;
                evenCurr = evenCurr->next;
            } else {
                oddCurr->next = curr;
                oddCurr = oddCurr->next;
            }
            curr = next;
            i++;
        }

        oddCurr->next = nullptr;
        evenCurr->next = oddHead;
        
        return evenHead;
    }
};
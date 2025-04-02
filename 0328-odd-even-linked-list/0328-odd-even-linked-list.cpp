
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
                cout<<curr->val<<" "<<"even"<<endl;
                evenCurr->next = curr;
                evenCurr = evenCurr->next;
            } else {
                 cout<<curr->val<<" "<<"odd"<<endl;
                oddCurr->next = curr;
                oddCurr = oddCurr->next;
            }
            curr = next;
            i++;
        }

        evenCurr->next = nullptr;
        oddCurr->next = NULL;

        evenCurr->next = oddHead;
        return evenHead;
    }
};
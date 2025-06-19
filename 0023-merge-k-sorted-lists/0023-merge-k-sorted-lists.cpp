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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (int i = 0; i < n; ++i) {
            if (lists[i])
                pq.push(lists[i]);
        }

        ListNode* head = NULL;
        ListNode* tail = head;

        while (!pq.empty()) {
            ListNode* tp = pq.top();
            pq.pop();
            if (!head) {
                head = tp;
                tail = head;
            } else {
                tail->next = tp;
                tail = tail->next;
            }

            if (tp->next)
                pq.push(tp->next);
        }

        return head;
    }
};
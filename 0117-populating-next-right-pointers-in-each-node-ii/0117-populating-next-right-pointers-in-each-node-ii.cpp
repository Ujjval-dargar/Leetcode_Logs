/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* head = root;

        if (!head)
            return head;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            Node* prev = NULL;
            int sz = q.size();

            for (int i = 0; i < sz; ++i) {
                Node* curr = q.front();
                q.pop();
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);

                if (i==sz-1){
                    curr->next = NULL;
                }
                if (i>0){
                    prev->next = curr;
                }

                prev = curr;
            }
        }

        return head;
    }
};
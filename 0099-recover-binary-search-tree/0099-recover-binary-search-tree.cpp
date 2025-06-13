/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;

    void f(TreeNode* curr) {
        if (!curr)
            return;

        f(curr->left);

        if (prev->val > curr->val) {
            if (!first) {
                first = prev;
                mid = curr;
            } else {
                last = curr;
            }
        }

        prev = curr;
        f(curr->right);
    }

    void recoverTree(TreeNode* root) {

        prev = new TreeNode(INT_MIN);
        first = mid = last = NULL;

        f(root);

        if (first && last) {
            swap(first->val, last->val);
        } else {
            swap(first->val, mid->val);
        }
    }
};
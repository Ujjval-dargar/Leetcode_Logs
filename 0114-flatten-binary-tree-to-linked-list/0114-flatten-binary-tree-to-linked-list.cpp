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
    void preorder(TreeNode* root, vector<TreeNode*>& ans) {
        if (!root)
            return;

        ans.push_back(root);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    void flatten(TreeNode* root) {
        if (!root)
            return;

        vector<TreeNode*> order;
        preorder(root, order);

        int n = order.size();
        for (int i = 0; i + 1 < n; ++i) {
            TreeNode* node = order[i];
            TreeNode* next = order[i + 1];

            node->left = NULL;
            node->right = next;
        }

    }
};
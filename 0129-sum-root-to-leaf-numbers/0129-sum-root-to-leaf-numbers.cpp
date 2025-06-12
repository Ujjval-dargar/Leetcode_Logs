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
    bool isLeaf(TreeNode* root) { return !root->left && !root->right; }

    void f(TreeNode* root, int curr, int& ans) {
        if (!root)
            return;

        int digit = root->val;
        if (isLeaf(root)) {
            ans += curr * 10 + digit;
            return;
        }

        f(root->left, curr * 10 + digit, ans);
        f(root->right, curr * 10 + digit, ans);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        f(root, 0, ans);
        return ans;
    }
};
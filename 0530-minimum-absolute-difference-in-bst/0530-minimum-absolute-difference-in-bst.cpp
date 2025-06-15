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
    void getInorder(TreeNode* root, vector<int>& inorder) {
        if (!root)
            return;

        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;
        getInorder(root, inorder);

        int ans = INT_MAX;
        int n = inorder.size();
        for (int i = 0; i + 1 < n; ++i) {
            ans = min(ans, inorder[i + 1] - inorder[i]);
        }

        return ans;
    }
};
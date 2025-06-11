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
    bool isleaf(TreeNode* root) {
        return root->left == NULL && root->right == NULL;
    }

    void f(TreeNode* root, string curr, vector<string>& ans) {

        if (isleaf(root)) {
            ans.push_back(curr);
            return;
        }

        if (root->left) f(root->left, curr + "->" + to_string(root->left->val),ans);
        if (root->right) f(root->right, curr + "->" + to_string(root->right->val),ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)
            return {};

        string temp = to_string(root->val);
        vector<string> ans;
        f(root, temp, ans);

        return ans;
    }
};
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
    pair<int, int> helper(TreeNode* root) {
        pair<int, int> p = {0, root->val};

        if (root->left != nullptr) {
            pair<int, int> pl = helper(root->left);
            p.first += max(pl.first, pl.second);
            p.second += pl.first;
        }

        if (root->right != nullptr) {
            pair<int, int> pr = helper(root->right);
            p.first += max(pr.first, pr.second);
            p.second += pr.first;
        }

        return {p.first, p.second};
    }

    int rob(TreeNode* root) {

        pair<int,int> ans=helper(root);
        return max(ans.first,ans.second);
    }
};
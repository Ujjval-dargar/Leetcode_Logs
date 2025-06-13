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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty())
            return NULL;

        TreeNode* root = new TreeNode(preorder.front());

        vector<int> left, right;
        for (int i : preorder) {
            if (i < root->val) left.push_back(i);
            if (i > root->val) right.push_back(i);
        }

        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);

        return root;
    }
};
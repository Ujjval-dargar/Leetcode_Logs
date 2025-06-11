/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool f(TreeNode* n1, TreeNode* n2 ){
        if (n1==NULL && n2==NULL) return true;

        if (n1==NULL || n2==NULL || n1->val!=n2->val) return false;

        return f(n1->left,n2->right) && f(n1->right,n2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        return f(root->left,root->right);
    }
};
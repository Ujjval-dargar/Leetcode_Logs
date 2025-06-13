/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while (root){
            
            int rootVal = root->val;
            int pVal = p->val;
            int qVal = q->val;

            if (pVal < rootVal &&  qVal < rootVal) root = root->left;
            else if (pVal > rootVal && qVal > rootVal) root = root->right;
            else return root;
        }

        return root;
    }
};
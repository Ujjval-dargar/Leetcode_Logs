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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;

        TreeNode* curr = root;
        if (curr->val == key) {
            return fix(curr);
        }

        while (curr){
            if (curr->val > key){
                if (curr->left && curr->left->val == key){
                    curr->left = fix(curr->left);
                    return root;
                }
                curr=curr->left;
            }
            else{
                if (curr->right && curr->right->val == key){
                    curr->right = fix(curr->right);
                    return root;
                }
                curr=curr->right;
            }
        }

        return root;
    }

    TreeNode* fix(TreeNode* node) {
        if (node->left == NULL) {
            return node->right;
        } else if (node->right == NULL) {
            return node->left;
        }

        TreeNode* right = node->right;
        TreeNode* last = findMax(node->left);

        last->right = right;
        return node->left;
    }

    TreeNode* findMax(TreeNode* node) {
        while (node->right)
            node = node->right;
        return node;
    }
};
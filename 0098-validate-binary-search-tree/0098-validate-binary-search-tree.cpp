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
    void getInorder(TreeNode* root, vector<int>& order) {
        if (!root)
            return;

        getInorder(root->left, order);
        order.push_back(root->val);
        getInorder(root->right, order);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> order;
        getInorder(root, order);

        int n = order.size();
        for (int i = 0; i + 1 < n; ++i) {
            if (order[i] >= order[i + 1]) {
                return false;
            }
        }

        return true;
    }
};
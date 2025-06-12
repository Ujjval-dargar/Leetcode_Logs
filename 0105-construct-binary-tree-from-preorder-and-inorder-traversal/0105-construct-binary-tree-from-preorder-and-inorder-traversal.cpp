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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (inorder.empty() || preorder.empty())
            return NULL;

        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        vector<int> nextPreorder(preorder.begin() + 1, preorder.end());

        int n = inorder.size();
        int idx = 0;
        while (idx < n && inorder[idx] != rootVal)
            idx++;

        vector<int> leftIn(inorder.begin(), inorder.begin() + idx);
        vector<int> rightIn(inorder.begin() + idx + 1, inorder.end());

        int leftSize = leftIn.size();
        vector<int> leftPre(nextPreorder.begin(),
                            nextPreorder.begin() + leftSize);
        vector<int> rightPre(nextPreorder.begin() + leftSize,
                             nextPreorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};
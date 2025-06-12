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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if (inorder.empty() || postorder.empty())
            return NULL;

        int rootVal = postorder.back();
        TreeNode* root = new TreeNode(rootVal);

        vector<int> nextpostorder(postorder.begin(),
                                  postorder.begin() + postorder.size() - 1);

        int n = inorder.size();
        int idx = 0;
        while (idx < n && inorder[idx] != rootVal)
            idx++;

        vector<int> leftIn(inorder.begin(), inorder.begin() + idx);
        vector<int> rightIn(inorder.begin() + idx + 1, inorder.end());

        int leftSize = leftIn.size();
        vector<int> leftPost(nextpostorder.begin(),
                             nextpostorder.begin() + leftSize);
        vector<int> rightPost(nextpostorder.begin() + leftSize,
                              nextpostorder.end());

        root->left = buildTree(leftIn, leftPost);
        root->right = buildTree(rightIn, rightPost);

        return root;
    }
};
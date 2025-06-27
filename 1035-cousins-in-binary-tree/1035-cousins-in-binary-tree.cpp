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
    void fill(TreeNode* root, int currDept, int currPar, vector<int>& depth,
              vector<int>& parent) {
        if (root == NULL)
            return;

        parent[root->val] = currPar;
        depth[root->val] = currDept;
        fill(root->left, currDept + 1, root->val, depth, parent);
        fill(root->right, currDept + 1, root->val, depth, parent);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> depth(101, -1);
        vector<int> parent(101, -1);

        fill(root, 0, -1, depth, parent);

        return depth[x] == depth[y] && parent[x] != parent[y];
    }
};
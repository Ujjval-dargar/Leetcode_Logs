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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};

        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int level = p.second;
            int sz = ans.size();

            if (sz < level + 1)
                ans.push_back({node->val});
            else
                ans[level].push_back(node->val);

            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }

        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> level = levelOrder(root);
        vector<int> ans;
        for (int i = 0; i < level.size(); ++i) {
            ans.push_back(level[i].back());
        }

        return ans;
    }
};
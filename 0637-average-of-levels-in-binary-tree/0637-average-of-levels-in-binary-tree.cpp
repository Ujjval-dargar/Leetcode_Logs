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
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};

        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            double curr = 0.0;
            int sz = q.size();

            for (int i=0;i<sz;++i){
                TreeNode* node = q.front();
                q.pop();

                curr += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            curr = curr/(double)sz;
            ans.push_back(curr);
        }

        return ans;
        
    }
};
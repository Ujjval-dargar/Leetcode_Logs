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
    void f(TreeNode* curr, TreeNode* par,
           unordered_map<TreeNode*, TreeNode*>& mp) {
        if (!curr)
            return;

        mp[curr] = par;
        f(curr->left, curr, mp);
        f(curr->right, curr, mp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        f(root, NULL, mp);

        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        unordered_map<TreeNode*, bool> visited;

        vector<int> ans;
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int dist = p.second;
            visited[node] = true;

            if (dist == k)
                ans.push_back(node->val);
            if (dist > k)
                break;

            if (mp[node] && !visited[mp[node]])
                q.push({mp[node], dist + 1});
            if (node->left && !visited[node->left])
                q.push({node->left, dist + 1});
            if (node->right && !visited[node->right])
                q.push({node->right, dist + 1});
        }

        return ans;
    }
};
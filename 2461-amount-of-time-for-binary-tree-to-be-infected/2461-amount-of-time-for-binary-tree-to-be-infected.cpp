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
    void f(TreeNode* curr, TreeNode* par,
           unordered_map<TreeNode*, TreeNode*>& mp) {
        if (!curr)
            return;
        mp[curr] = par;
        f(curr->left, curr, mp);
        f(curr->right, curr, mp);
    }

    bool find(TreeNode* root, int start, TreeNode*& ans) {
        if (!root)
            return false;
        if (root->val == start) {
            ans = root;
            return true;
        }

        if (find(root->left, start, ans))
            return true;
        if (find(root->right, start, ans))
            return true;

        return false;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mp;
        f(root, NULL, mp);

        TreeNode* strt = NULL;
        find(root, start, strt);

        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({strt, 0});

        unordered_map<TreeNode*, bool> visited;

        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int dist = p.second;
            visited[node] = true;

            ans = max(ans,dist);

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
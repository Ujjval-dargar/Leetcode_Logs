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
    void f(TreeNode* root, int i, int j, vector<vector<int>>& arr) {
        if (root == NULL)
            return;

        arr.push_back({j, i, root->val});
        f(root->left, i + 1, j - 1, arr);
        f(root->right, i + 1, j + 1, arr);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> arr;

        f(root, 0, 0, arr);
        sort(arr.begin(), arr.end());

        int n = arr.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[arr[i][0]].push_back(arr[i][2]);
        }

        vector<vector<int>> ans;
        for (auto i : mp) {
            ans.push_back(i.second);
        }

        return ans;
    }
};
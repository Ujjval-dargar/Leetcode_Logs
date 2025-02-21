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
class FindElements {
public:
    unordered_map<int, bool> mp;
    TreeNode* tree = nullptr;

    FindElements(TreeNode* root) { helper(root,0); }

    void helper(TreeNode* root, int val) {
        if (root == nullptr) {
            return;
        }

        mp[val] = true;
        helper(root->left, 2 * val + 1);
        helper(root->right, 2 * val + 2);
    }

    bool find(int target) { return mp[target]; }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
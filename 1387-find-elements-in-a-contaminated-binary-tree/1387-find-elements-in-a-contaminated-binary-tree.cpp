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

    FindElements(TreeNode* root) { helper(root); }

    void helper(TreeNode* root) {
        if (tree == nullptr) {
            tree = root;
            root->val = 0;
        }

        cout << root->val << endl;

        mp[root->val] = true;

        if (root->left != nullptr) {
            root->left->val = 2 * root->val + 1;
            helper(root->left);
        }

        if (root->right != nullptr) {
            root->right->val = 2 * root->val + 2;
            helper(root->right);
        }
    }

    bool find(int target) { return mp[target]; }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
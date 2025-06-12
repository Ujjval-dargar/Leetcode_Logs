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
class BSTIterator {
public:
    TreeNode* root;
    vector<TreeNode*> inorder;
    int curr = 0;

    void getInorder(TreeNode* root, vector<TreeNode*>& inorder) {
        if (!root)
            return;

        getInorder(root->left, inorder);
        inorder.push_back(root);
        getInorder(root->right, inorder);
    }

    BSTIterator(TreeNode* _root) {
        root = _root;
        getInorder(root, inorder);
    }

    int next() {
        int val = inorder[curr]->val;
        curr++;
        return val;
    }

    bool hasNext() {
        if (curr < inorder.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
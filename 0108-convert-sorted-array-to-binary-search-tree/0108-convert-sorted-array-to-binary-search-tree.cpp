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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return NULL;
        int mid = n/2;
        TreeNode* root = new TreeNode(nums[mid]);

        vector<int> nums_left, nums_right;
        for (int i = 0; i < mid; ++i){
            nums_left.push_back(nums[i]);
        }
        for (int i = mid + 1; i < n; ++i){
            nums_right.push_back(nums[i]);
        }
        root->left = sortedArrayToBST(nums_left);
        root->right = sortedArrayToBST(nums_right);
        return root;
    }
};
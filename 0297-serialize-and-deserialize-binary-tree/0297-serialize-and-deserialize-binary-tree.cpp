/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        string tree;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                tree += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else
                tree += "#,";
        }

        return tree;
    }

    vector<string> split(string data) {

        vector<string> ans;
        string s;

        int n = data.size();
        for (int i = 0; i < n; ++i) {
            if (data[i] == ',') {
                ans.push_back(s);
                s = "";
            } else {
                s.push_back(data[i]);
            }
        }

        if (s != "")
            ans.push_back(s);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return NULL;

        vector<string> tree = split(data);
        TreeNode* root = new TreeNode(stoi(tree[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            string s;

            s = tree[i];
            i++;
            if (s != "#") {
                node->left = new TreeNode(stoi(s));
                q.push(node->left);
            }

            s = tree[i];
            i++;
            if (s != "#") {
                node->right = new TreeNode(stoi(s));
                q.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
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
        string serial;
        if (root) {
            serial = to_string(root->val) + string(",") + serialize(root->left) + string(",") + serialize(root->right);
        }
        else {
            serial = string("null");
        }
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t pos = 0;
        return deserialize1(pos, data);
    }
    TreeNode* deserialize1(size_t &current, const string &data) {
        TreeNode *root = NULL;
        if (current >= data.length()) {
            return root;
        }
        size_t delimiter = data.find(',', current);
        string root_str = data.substr(current, delimiter - current);
        current = delimiter;
        if (string("null") != root_str) {
            root = new TreeNode(atoi(root_str.c_str()));
            ++ current;
            root->left = deserialize1(current, data);
            ++ current;
            root->right = deserialize1(current, data);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        string serial;
        serialize(root, serial);
        return serial;
    }
    void serialize(TreeNode *root, string &serial) {
        serial += string(serial.size() ? "," : "");
        if (root) {
            serial += to_string(root->val);
            serialize(root->left, serial);
            serialize(root->right, serial);
        }
        else {
            serial += "#";
        }
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        size_t pos = 0;
        return deserialize(data, pos);
    }
    TreeNode *deserialize(const string &data, size_t &pos) {
        TreeNode *root = NULL;
        if (pos < data.length()) {
            size_t comma = data.find(',', pos);
            if ('#' != data[pos]) {
                root = new TreeNode(stoi(data.substr(pos, comma)));
                pos = comma + 1;
                root->left = deserialize(data, pos);
                root->right = deserialize(data, pos);
            }
            else {
                pos = comma + 1;
            }
        }
        return root;
    }
};

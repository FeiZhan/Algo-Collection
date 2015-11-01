//@result Runtime Error

#include <iostream>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

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

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
	void print(void) {
		cout <<"{" << val << ", ";
		if (this->left) {
			this->left->print();
		}
		else {
			cout << "#";
		}
		cout << ", ";
		if (this->right) {
			this->right->print();
		}
		else {
			cout << "#";
		}
		cout <<"}";
	}
};

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
		queue<TreeNode *> node_queue;
		node_queue.push(root);
		while (! node_queue.empty()) {
			TreeNode *current = node_queue.front();
			node_queue.pop();
			if (current) {
				serial += to_string(current->val);
				node_queue.push(current->left);
				node_queue.push(current->right);
			}
			else {
				serial += "#";
			}
			serial += ",";
		}
		while (serial.length() && (serial.back() == ',' || serial.back() == '#')) {
			serial.erase(serial.length() - 1);
		}
		serial = "{" + serial + "}";
		return serial;
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
		queue<TreeNode *> node_queue;
		TreeNode *root = new TreeNode(INT_MAX);
		node_queue.push(root);
		for (size_t i = 1; i + 1 < data.length(); ++ i) {
			if (',' != data[i]) {
				TreeNode *current = node_queue.front();
				node_queue.pop();
				if ('#' == data[i]) {
					delete current;
					current = NULL;
				}
				else {
					int num(0);
					while (i < data.length() && data[i] >= '0' && data[i] <= '9') {
						num = num * 10 + static_cast<int> (data[i] - '0');
						++ i;
					}
					-- i;
					current->val = num;
					current->left = new TreeNode(INT_MAX);
					node_queue.push(current->left);
					current->right = new TreeNode(INT_MAX);
					node_queue.push(current->right);
				}
			}
		}
		stack<TreeNode *> node_stack;
		node_stack.push(root);
		while (! node_stack.empty()) {
			TreeNode *current = node_stack.top();
			node_stack.pop();
			if (current) {
				if (current->left && INT_MAX == current->left->val && NULL == current->left->left && NULL == current->left->right) {
					//delete current->left;
					current->left = NULL;
				}
				if (current->left) {
					node_stack.push(current->left);
				}
				if (current->right && INT_MAX == current->right->val && NULL == current->right->left && NULL == current->right->right) {
					//delete current->right;
					current->right = NULL;
				}
				if (current->right) {
					node_stack.push(current->right);
				}
			}
		}
		return root;
    }
};

int main() {
	// your code goes here
	Solution s;
	//{1,#,2}
	//{1,2,3,#,#,4,5}
	string data("{1,2,3,#,#,4,5}");
	TreeNode *root = s.deserialize(data);
	root->print();
	cout << endl;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	cout << s.serialize(root) << endl;
	cout << s.serialize(s.deserialize(data)) << endl;
	return 0;
}
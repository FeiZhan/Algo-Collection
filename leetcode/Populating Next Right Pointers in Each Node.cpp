/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeLinkNode *> node_vec, child_vec;
        node_vec.push_back(root);
        while (node_vec.size())
        {
			child_vec.clear();
			for (int i = 0; i < node_vec.size(); ++ i)
			{
				// maybe the root is NULL
				if (NULL == node_vec[i])
				{
					continue;
				}
				if (node_vec.size() > i + 1)
				{
					node_vec[i]->next = node_vec[i + 1];
				}
				if (NULL != node_vec[i]->left)
				{
					child_vec.push_back(node_vec[i]->left);
				}
				if (NULL != node_vec[i]->right)
				{
					child_vec.push_back(node_vec[i]->right);
				}
			}
			node_vec.clear();
			for (int i = 0; i < child_vec.size(); ++ i)
			{
				node_vec.push_back(child_vec[i]);
			}
		}
		return;
    }
};

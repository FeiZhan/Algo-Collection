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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
		return generateTrees(1, n);
    }
	vector<TreeNode *> generateTrees(int begin, int end) {
		if (tree_map.end() == tree_map.find(make_pair(begin, end))) {
			tree_map[make_pair(begin, end)] = vector<TreeNode *> ();
			if (0 == end || begin > end) {
				tree_map[make_pair(begin, end)].push_back(NULL);
			}
			else {
				for (size_t i = begin; i <= end; ++ i) {
					vector<TreeNode *> left = generateTrees(begin, i - 1);
					vector<TreeNode *> right = generateTrees(i + 1, end);
					for (size_t j = 0; j < left.size(); ++ j) {
						for (size_t k = 0; k < right.size(); ++ k) {
							TreeNode *root = new TreeNode(i);
							root->left = left[j];
							root->right = right[k];
							tree_map[make_pair(begin, end)].push_back(root);
						}
					}
				}
			}
		}
		return tree_map[make_pair(begin, end)];
	}
	map<pair<int, int>, vector<TreeNode *> > tree_map;
};

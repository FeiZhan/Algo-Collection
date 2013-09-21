// the comparison is between max depth and min depth, not between max depth of two children.
// just compare for once, not every time recursively.

int maxDepth(const TreeNode *root)
{
	if (NULL == root)
	{
		return 0;
	}
	return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}
int minDepth(const TreeNode *root)
{
	if (NULL == root)
	{
		return 0;
	}
	return 1 + std::min(minDepth(root->left), minDepth(root->right))
}
bool isBalanced(const TreeNode *root)
{
	return maxDepth(root) - minDepth(root) <= 1;
}

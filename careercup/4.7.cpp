bool containTree(TreeNode *t1, TreeNode *t2)
{
	if (NULL == t2)
	{
		return true;
	} else
	{
		return subTree(t1, t2);
	}
}
bool subTree(TreeNode *r1, TreeNode *r2)
{
	if (NULL == r1)
	{
		return false;
	}
	if (r1->val == r2->val && matchTree(r1, r2))
	{
		return true;
	}
	return (subTree(r1->left, r2) || subTree(r1->right, r2));
}
bool matchTree(TreeNode *r1, TreeNode *r2)
{
	if (NULL == r1 && NULL == r2)
	{
		return true;
	}
	if (NULL == r1 || NULL == r2 || r1.data != r2.data)
	{
		return false;
	}
	return matchTree(r1.left, r2.left) && matchTree(r1.right, r2.right);
}

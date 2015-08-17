// attempt 2
TreeNode *commonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (cover(root->left, p) && cover(root->left, q))
	{
		return commonAncestor(root->left, p, q);
	}
	if (cover(root->right, p) && cover(root->right, q))
	{
		return commonAncestor(root->right, p, q);
	}
	return root;
}
bool cover(TreeNode *root, TreeNode *p)
{
	if (NULL == root)
	{
		return false;
	}
	if (root == p)
	{
		return true;
	}
	return cover(root->left, p) || cover(root->right, p);
}
// attempt 3
int cover(TreeNode *root, TreeNode *p, TreeNode *q)
{
	enum ret = NO_NODES_FOUND;
	if (NULL == root)
	{
		return ret;
	}
	if (root == p || root == q)
	{
		ret = ONE_NODE_FOUND;
	}
	ret += cover(root->left, p, q);
	if (TWO_NODES_FOUND == ret)
	{
		return ret;
	}
	return ret + cover(root->right, p, q);
}
TreeNode *commonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (q == p && (root->left == q || root->right == q))
	{
		return root;
	}
	int nodesFromLeft = cover(root->left, p, q);
	if (TWO_NODES_FOUND == nodesFromLeft)
	{
		if (root->left == p || root->left == q)
		{
			return root->left;
		} else
		{
			return commonAncestor(root->left, p, q);
		}
	}
	else if (ONE_NODE_FOUND == nodeFromLeft)
	{
		if (root == p)
		{
			return p;
		}
		else if (root == q)
		{
			return q;
		}
	}
	int nodesFromRight = cover(root->right, p, q);
	if (TWO_NODES_FOUND == nodesFromRight)
	{
		if (root->right == p || root->right == q)
		{
			return root->right;
		} else
		{
			return commonAncestor(root->right, p, q);
		}
	}
	else if (ONE_NODE_FOUND == nodesFromRight)
	{
		if (root == p)
		{
			return p;
		}
		else if (root == q)
		{
			return q;
		}
	}
	if (ONE_NODE_FOUND == nodesFromLeft && ONE_NODE_FOUND == nodesFromRight)
	{
		return root;
	} else
	{
		return NULL;
	}
}

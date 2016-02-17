# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        return self.helper(root, 0)

    def helper(self, root, path):
    	if root:
    		path = path * 10 + root.val
    		if None == root.left and None == root.right:
    			return path
    		else:
    			return self.helper(root.left, path) + self.helper(root.right, path)
    	else:
    		return 0
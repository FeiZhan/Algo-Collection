# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        return self.helper(root, - sys.maxint, sys.maxint)
    def helper(self, root, minimum, maximum):
    	return None == root or (root.val > minimum and root.val < maximum and self.helper(root.left, minimum, root.val) and self.helper(root.right, root.val, maximum))
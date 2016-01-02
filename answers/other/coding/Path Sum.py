# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
      	
        return (None != root and None == root.left and None == root.right and root.val == sum) or (None != root and (self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)))
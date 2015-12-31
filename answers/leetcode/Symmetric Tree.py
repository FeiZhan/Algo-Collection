# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """

        return None == root or (None == root.left and None == root.right) or self.isMirror(root.left, root.right)

    def isMirror(self, left, right):
        return (None == left and None == right) or (None != left and None != right and left.val == right.val and self.isMirror(left.left, right.right) and self.isMirror(left.right, right.left))

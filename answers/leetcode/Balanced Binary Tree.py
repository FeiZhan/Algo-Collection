# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """

        return self.getDepth(root) >= 0

    def getDepth(self, root):
        if root:
            left = self.getDepth(root.left)
            if left < 0:
                return left
            right = self.getDepth(root.right)
            if right < 0:
                return right
            if abs(left - right) > 1:
                return -1
            else:
                return max(left, right) + 1
        else:
            return 0

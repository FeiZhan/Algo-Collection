# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        sum: int = 0
        if root is not None:
            sum = self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)
            if root.left is not None and root.left.left is None and root.left.right is None:
                sum += root.left.val
        return sum

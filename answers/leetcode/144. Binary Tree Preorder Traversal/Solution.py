# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result: List[int] = []
        if root != None:
            result.append(root.val)
            if root.left != None:
                result += self.preorderTraversal(root.left)
            if root.right != None:
                result += self.preorderTraversal(root.right)
        return result

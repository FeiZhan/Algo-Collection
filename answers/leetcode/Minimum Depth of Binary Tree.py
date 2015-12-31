# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        queue = [root]
        min_depth = -1
        while len(queue):
            min_depth += 1
            for i in range(len(queue)):
                current = queue.pop(0)
                if current:
                    if None == current.left and None == current.right:
                        return min_depth + 1
                    queue.append(current.left)
                    queue.append(current.right)
        return min_depth

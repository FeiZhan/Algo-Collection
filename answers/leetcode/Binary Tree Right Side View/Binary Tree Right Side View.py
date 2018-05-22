# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """

        right_list = []
        queue = [root]
        while len(queue):
            right = None
            for i in range(len(queue)):
                current = queue.pop(0)
                if current:
                    if None == right:
                        right = current.val
                    queue.append(current.right)
                    queue.append(current.left)
            if right:
                right_list.append(right)
        return right_list

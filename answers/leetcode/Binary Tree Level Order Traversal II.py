# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """

        level_list = []
        self.dfs(0, root, level_list)
        return level_list[: : -1]

    def dfs(self, level, root, level_list):
        if None == root:
            return
        while len(level_list) <= level:
            level_list.append([])
        level_list[level].append(root.val)
        self.dfs(level + 1, root.left, level_list)
        self.dfs(level + 1, root.right, level_list)

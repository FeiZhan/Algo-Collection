# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """

        path_list = []
        self.helper(root, [], path_list)
        return path_list

    def helper(self, root, path, path_list):
        if None == root:
            return
        path.append(root.val)
        if None == root.left and None == root.right:
            if len(path) > 0:
                path_list.append(str(path[0]))
                for j in range(1, len(path)):
                    path_list[-1] += "->" + str(path[j])
        self.helper(root.left, path, path_list)
        self.helper(root.right, path, path_list)
        path.pop()

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        
        path_list = []
        self.dfs(root, [], sum, path_list)
        return path_list

    def dfs(self, root, path, sum, path_list):
    	if root:
    		if None == root.left and None == root.right and root.val == sum:
    			path_list.append(path + [root.val])
    		self.dfs(root.left, path + [root.val], sum - root.val, path_list)
    		self.dfs(root.right, path + [root.val], sum - root.val, path_list)
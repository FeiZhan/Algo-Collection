# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
	def flatten(self, root):
		"""
		:type root: TreeNode
		:rtype: void Do not return anything, modify root in-place instead.
		"""
		
		self.helper(root)

	def helper(self, root):
		end = None
		if root:
			right_begin, right_end = self.helper(root.right)
			if right_end:
				end = right_end
			if root.left:
				left_begin, left_end = self.helper(root.left)
				root.left = None
				root.right = left_begin
				left_end.right = right_begin
				if None == end:
					end = left_end
		if None == end:
			end = root
		return [root, end]
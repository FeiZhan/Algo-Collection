# Definition for binary tree with next pointer.
# class TreeLinkNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution(object):
	def connect(self, root):
		"""
		:type root: TreeLinkNode
		:rtype: nothing
		"""
		
		if root:
			outgoing = None
			if root.left:
				if root.right:
					root.left.next = root.right
				else:
					outgoing = root.left
			if root.right:
				outgoing = root.right
			if outgoing:
				current = root.next
				while current:
					if current.left:
						outgoing.next = current.left
						break
					elif current.right:
						outgoing.next = current.right
						break
					current = current.next
			self.connect(root.left)
			self.connect(root.right)

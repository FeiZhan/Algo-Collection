# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        
        inorder = []
        stack = [root]
        while len(stack):
        	current = stack.pop()
        	if current:
        		if len(stack) and stack[-1] == current.right:
        			inorder.append(current.val)
        		else:
        			stack.append(current.right)
        			stack.append(current)
        			stack.append(current.left)
        return inorder
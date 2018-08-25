# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """

        wrong_nodes = [None, None]
        self.findWrongNodes(root, None, wrong_nodes)
        wrong_nodes[0].val, wrong_nodes[1].val = wrong_nodes[1].val, wrong_nodes[0].val

    def findWrongNodes(self, root, prev, wrong_nodes):
        if root:
            prev1 = self.findWrongNodes(root.left, prev, wrong_nodes)
            if prev1:
                prev = prev1
            if prev and prev.val > root.val:
                if None == wrong_nodes[0]:
                    wrong_nodes[0] = prev
                wrong_nodes[1] = root
            next = self.findWrongNodes(root.right, root, wrong_nodes)
            return next if next else root
        return root

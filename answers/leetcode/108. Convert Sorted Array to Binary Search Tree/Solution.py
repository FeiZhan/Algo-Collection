# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if nums == None or len(nums) == 0:
            return None
        else:
            return self.sort(0, len(nums) - 1, nums)

    def sort(self, start: int, end: int, nums: List[int]) -> Optional[TreeNode]:
        if start > end:
            return None
        elif start == end:
            return TreeNode(nums[start])
        else:
            middle: int = (start + end) // 2
            root: TreeNode = TreeNode(nums[middle])
            root.left = self.sort(start, middle - 1, nums)
            root.right = self.sort(middle + 1, end, nums)
            return root

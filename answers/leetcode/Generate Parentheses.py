class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        parent_list = []
        self.helper(0, n, "", parent_list)
        return parent_list
    def helper(self, left, total, parent, parent_list):
        if left >= total and len(parent) >= total + total:
            parent_list.append(parent)
            return
        if left < total:
            self.helper(left + 1, total, parent + '(', parent_list)
        if len(parent) < left + left:
            self.helper(left, total, parent + ')', parent_list)

class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """

        path_list = []
        prev = 0
        for i in range(len(path) + 1):
            if len(path) == i or '/' == path[i]:
                if prev + 2 == i and '.' == path[i - 2] and '.' == path[i - 1]:
                    if len(path_list):
                        path_list.pop()
                elif i - prev > 0 and not (prev + 1 == i and '.' == path[prev]):
                    path_list.append(path[prev : (i if i < len(path) else i + 1)])
                prev = i + 1
        return '/' + '/'.join(path_list)

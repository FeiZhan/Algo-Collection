#@result TLE

class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """

        for i in range(len(board)):
            for j in range(len(board[i])):
                if self.dfs(i, j, board, 0, word):
                    return True
        return False

    def dfs(self, x, y, board, pos, word):
        if x < 0 or x >= len(board) or y < 0 or y >= len(board[x]) or '.' == board[x][y] or pos < 0:
            return False
        elif pos >= len(word):
            return True
        elif board[x][y] != word[pos]:
            return False
        board[x][y] = '.'
        if self.dfs(x - 1, y, board, pos + 1, word) or self.dfs(x + 1, y, board, pos + 1, word)or self.dfs(x, y - 1, board, pos + 1, word) or self.dfs(x, y + 1, board, pos + 1, word):
            return True
        board[x][y] = word[pos]
        return False

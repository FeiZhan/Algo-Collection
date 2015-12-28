class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        for i in range(len(board)):
            sudoku = {}
            for j in range(len(board[i])):
                if board[i][j] in sudoku:
                    return False
                elif '.' != board[i][j]:
                    sudoku[board[i][j]] = 1
        for i in range(len(board[0])):
            sudoku = {}
            for j in range(len(board)):
                if board[j][i] in sudoku:
                    return False
                elif '.' != board[j][i]:
                    sudoku[board[j][i]] = 1
        for i in range(3):
            for j in range(3):
                sudoku = {}
                for m in range(len(board) / 3):
                    for n in range(len(board) / 3):
                        if board[i * 3 + m][j * 3 + n] in sudoku:
                            return False
                        elif '.' != board[i * 3 + m][j * 3 + n]:
                            sudoku[board[i * 3 + m][j * 3 + n]] = 1
        return True

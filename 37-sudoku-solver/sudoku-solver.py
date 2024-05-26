
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def row_check(row):
            seen = set()
            for val in board[row]:
                if val != '.':
                    if val in seen:
                        return False
                    seen.add(val)
            return True

        def col_check(col):
            seen = set()
            for i in range(9):
                if board[i][col] != '.':
                    if board[i][col] in seen:
                        return False
                    seen.add(board[i][col])
            return True

        def grid_check(row, col):
            seen = set()
            start_row, start_col = 3 * (row // 3), 3 * (col // 3)
            for i in range(start_row, start_row + 3):
                for j in range(start_col, start_col + 3):
                    if board[i][j] != '.':
                        if board[i][j] in seen:
                            return False
                        seen.add(board[i][j])
            return True
        
        def check_valid(row, col):
            return row_check(row) and col_check(col) and grid_check(row, col)
        
        def backtrack():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for val in map(str, range(1, 10)):
                            board[i][j] = val
                            if check_valid(i, j) and backtrack():
                                return True
                            board[i][j] = '.'
                        return False
            return True
        
        backtrack()

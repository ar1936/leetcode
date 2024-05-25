class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        existing_queen_ind = []
        def column_check(x, y):
            for i, j in existing_queen_ind:
                if j == y:
                    return False
            return True

        def diagonal_check(x, y):
            gap = x - y
            sum = x + y
            for i, j in existing_queen_ind:
                if i - j == gap or i + j == sum:
                    return False
            return True


        def can_place_queen(x, y):
            return column_check(x, y) and diagonal_check(x, y)

        def create_board():
            board = [['.' for _ in range(n)] for _ in range(n)]
            for x, y in existing_queen_ind:
                board[x][y] = 'Q'
            return ["".join(row) for row in board]
        
        def backtrack(row):
            if row == n:
                ans.append(create_board())
                return
            for col in range(n):
                if can_place_queen(row, col):
                    existing_queen_ind.append((row, col))
                    backtrack(row + 1)
                    existing_queen_ind.pop()
        ans = []
        backtrack(0)

        return ans

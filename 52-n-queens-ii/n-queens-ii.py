class Solution:
    def totalNQueens(self, n: int) -> int:
        existing_queen_ind = []
        ans = []
        def check_col(x,y):
            for (i,j) in existing_queen_ind:
                if y == j:
                    return False
            return True
        
        def check_dia(x,y):
            for (i,j) in existing_queen_ind:
                if (x+y == i+j) or (i-j == x-y):
                    return False
            return True
        def check_valid(x,y):
            return check_col(x,y) and check_dia(x,y)
        
        def make_board():
            board = []
            for i in range(n):
                st = ""
                for j in range(n):
                    if (i,j) in existing_queen_ind:
                        st+='Q'
                    else:
                        st+="."
                board.append(st)
            return board

        def backtracking(row):
            if row == n:
                ans.append(make_board())
                return
            
            for col in range(n):
                if check_valid(row,col):
                    existing_queen_ind.append((row,col))
                    backtracking(row+1)
                    existing_queen_ind.pop()
            
        backtracking(0)
        return len(ans)
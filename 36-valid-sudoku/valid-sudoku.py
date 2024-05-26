# k = (x // 3) * 3 + y // 3
#             i_lower = (k // 3) * 3
#             i_upper = i_lower + 3 

#             j_lower = (k % 3) * 3
#             j_upper = j_lower + 3  
            
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def row_check(x,y):
            row = set()
            for i in range(9):
                if board[i][j]!='.' and board[i][y] in row:
                    return False
                row.add(board[i][y])
            return True

        def col_check(x,y):
            col = set()
            for j in range(9):
                if board[i][j]!='.' and board[x][j] in col:
                    return False
                col.add(board[x][j])
            return True

        def small_mat_check(x,y):
            small_mat = set()
            k = (x // 3) * 3 + y // 3
            i_lower = (k // 3) * 3
            i_upper = i_lower + 3 

            j_lower = (k % 3) * 3
            j_upper = j_lower + 3  
            
            for i in range(i_lower, i_upper):
                for j in range(j_lower, j_upper):
                    if((i//3 + j//3) == (x//3 + y//3)):
                        if board[i][j]!='.' and  board[i][j] in small_mat:
                            return False
                        small_mat.add(board[i][j])
            return True
        
        for i in range(9):
            for j in range(9):
                if board[i][j]!= '.' and (row_check(i,j) == False or col_check(i,j)==False or small_mat_check(i,j)==False):
                    return False
        return True
                    
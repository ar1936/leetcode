class Solution:
    def isValidSudoku(self, mat: List[List[str]]) -> bool:
        n = len(mat)
        m = len(mat[0])

        def check_row(x,y):
            row_set = set()
            for i in range(m):
                if mat[x][i] != '.' and mat[x][i] in row_set:
                    print(3,x,i)
                    return False
                row_set.add(mat[x][i])
            return True
        
        def check_col(x,y):
            col_set = set()
            for i in range(m):
                if mat[i][y] != '.' and mat[i][y] in col_set:
                    print(2,i,y)
                    return False
                col_set.add(mat[i][y])
            return True

        def check_mat(x, y):
            mat_set = set()
            i_lower = (x // 3) * 3
            j_lower = (y // 3) * 3
            for i in range(i_lower, i_lower + 3):
                for j in range(j_lower, j_lower + 3):
                    if mat[i][j] != '.' and mat[i][j] in mat_set: 
                        return False
                    mat_set.add(mat[i][j])
            return True


        for i in range(n):
            for j in range(m):
                if mat[i][j] != '.':
                    if check_row(i,j) == False or check_col(i,j) == False or  check_mat(i,j) == False:
                        return False
        return True


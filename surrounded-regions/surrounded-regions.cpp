// class Solution {
// public:
//     void mark_visited(vector<vector<char>>&board,int x,int y,int N,int M){
//         if(x<0||x>=N||y<0||y>=M||board[x][y]=='X')
//             return ;
//         if(board[x][y]=='O')
//             board[x][y]='D';
//         mark_visited(board,x,y+1,N,M);
//         mark_visited(board,x-1,y,N,M);
//         mark_visited(board,x+1,y,N,M);
//         mark_visited(board,x,y-1,N,M);
//     }
//     void solve(vector<vector<char>>& board) {
//         int N=board.size();
//         int M=board[0].size();
//         // if(!board.size()) 
//         //     return;
//         for(int i=0;i<N;i++){
//                 mark_visited(board,i,0,N,M);
//            if(M>1) //check for last row
//                 mark_visited(board,i,M-1,N,M);
//        }
//         for(int j=1;j<M-1;j++){
//                 mark_visited(board,0,j,N,M);
//             if(N>1) // check for last column
//                 mark_visited(board,N-1,j,N,M);
//         }
//         for(int i=0;i<N;i++){
//             for(int j=0;j<M;j++){
//                 if(board[i][j]=='O')
//                     board[i][j]='X';
//                 else if(board[i][j]=='D')
//                     board[i][j]='O';
//             }
//         }
         
//     }
// };

class Solution {
public:
    void solve(vector<vector<char>>& board) {
       
        int rows = board.size();
        int cols = board[0].size();
        
        // Go through boarder to find 'O'
        for(int i=0; i<rows; ++i) {
            DFS(board, i, 0, rows, cols);
            if(cols>1) DFS(board, i, cols-1, rows, cols);
        }
        for(int i=1; i<cols-1; ++i) {
            DFS(board, 0, i, rows, cols);
            if(rows>1) DFS(board, rows-1, i, rows, cols);
        }
        
        // Go through whole board and mark 'O' as 'X', 'D' as 'O'
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                if(board[i][j]=='O') board[i][j] = 'X';
                else if(board[i][j]=='D') board[i][j] = 'O';
            }
        }
    }
    
    void DFS(vector<vector<char>>& board, int i, int j, int rows, int cols) {
        if(i<0 || i>=rows || j<0 || j>=cols || board[i][j]=='X' || board[i][j]=='D') return;
        
        // If current is 'O', mark as 'D' and preform DFS
        if(board[i][j]=='O') board[i][j] = 'D';
        
        DFS(board, i-1, j, rows, cols);
        DFS(board, i+1, j, rows, cols);
        DFS(board, i, j-1, rows, cols);
        DFS(board, i, j+1, rows, cols);
    }
};

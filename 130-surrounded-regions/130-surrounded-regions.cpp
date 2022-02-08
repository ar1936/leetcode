int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
class Solution {
    void dfs(vector<vector<char>>&board,int x ,int y){
        int row=board.size(),col=board[0].size();
        if(x<0||x>=row||y<0||y>=col||board[x][y]=='X'||board[x][y]=='A')
            return ;
        if(board[x][y]=='O')
            board[x][y]='A';
        for(int i=0;i<4;i++){
            dfs(board,x+dx[i],y+dy[i]);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int row=board.size(),col=board[0].size();
        for(int i=0;i<row;i++){
            dfs(board,i,0);
            if(col>1)
                dfs(board,i,col-1);
        }
        for(int j=0;j<col;j++){
            dfs(board,0,j);
            if(row>1)
                dfs(board,row-1,j);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='A')
                    board[i][j]='O';
            }
        }   
    }
};

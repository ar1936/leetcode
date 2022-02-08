int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
class Solution {
    void dfs(vector<vector<char>>&grid, int x, int y){
        int row=grid.size(),col=grid[0].size();
        if(x<0||x>=row||y<0|y>=col||grid[x][y]=='0')
            return ;
        if(grid[x][y]=='1'){
            grid[x][y]='0';
            
        }
        for(int i=0;i<4;i++){
            dfs(grid,x+dx[i],y+dy[i]);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size(),col=grid[0].size(),ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};
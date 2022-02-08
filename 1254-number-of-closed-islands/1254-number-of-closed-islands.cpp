int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int ans=0;
class Solution {
    void dfs(vector<vector<int>>&grid, int x, int y){
        int row=grid.size(),col=grid[0].size();
        if(x<0||x>=row||y<0||y>=col||grid[x][y]==1)
            return;
        grid[x][y]=1;
        for(int i=0;i<4;i++){
            dfs(grid,x+dx[i],y+dy[i]);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0||j==0||i==row-1||j==col-1){
                    if(grid[i][j]==0)
                        dfs(grid,i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
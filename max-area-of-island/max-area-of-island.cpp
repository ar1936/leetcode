class Solution {
public:
    int solve(vector<vector<int>>&grid,int x,int y,int N,int M){
        if(x<0||x>=N||y<0||y>=M||grid[x][y]==0)
            return 0;
        if(grid[x][y]==1){
            grid[x][y]=0;
        }
        return 1+solve(grid,x-1,y,N,M)+solve(grid,x+1,y,N,M)+solve(grid,x,y-1,N,M)+solve(grid,x,y+1,N,M);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int N=grid.size();
        int M=grid[0].size();
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==1)
                {
                    
                    ans=max(ans,solve(grid,i,j,N,M));
                }
            }
        }
        return ans;
    }
};
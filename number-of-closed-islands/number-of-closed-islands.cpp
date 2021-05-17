class Solution {
public:
    void solve(vector<vector<int>>&grid,int x,int y,int N,int M){
        if(x<0||x>=N||y<0||y>=M||grid[x][y]==1)
            return ;
        grid[x][y]=1;
        solve(grid,x+1,y,N,M);
        solve(grid,x-1,y,N,M);
        solve(grid,x,y-1,N,M);
        solve(grid,x,y+1,N,M);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int N=grid.size();
        int M=grid[0].size();
        int ans=0;
        for(int i=0;i<N;i++){
            solve(grid,i,0,N,M);
            if(M>1)
                solve(grid,i,M-1,N,M);
        }
        for(int j=1;j<M-1;j++){
            solve(grid,0,j,N,M);
            if(N>1)
                solve(grid,N-1,j,N,M);
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j]==0){
                    solve(grid,i,j,N,M);
                    ans++;
                }
            }
        }
        return ans;
    }
};
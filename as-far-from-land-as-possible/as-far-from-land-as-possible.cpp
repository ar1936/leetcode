int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
class Solution {
    public:
  
    int maxDistance(vector<vector<int>>& grid) {
        int N=grid.size();
        int M= grid[0].size();
        int ans=-1;
        bool flag=true;
        vector<vector<int>>distance(N,vector<int>(M,0));
        queue<pair<int,int>>q;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    distance[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int new_x=x+dx[k];
                int new_y=y+dy[k];
                if(new_x>=0&&new_x<N&&new_y>=0&&new_y<M&&(grid[new_x][new_y]==0)){
                        q.push({new_x,new_y});
                        grid[new_x][new_y]=grid[x][y]+1;
                        ans=max(ans,grid[new_x][new_y]);
                        flag=false;
                }
            }
        }
       return (ans>0?ans-1:-1);
        
    }
};
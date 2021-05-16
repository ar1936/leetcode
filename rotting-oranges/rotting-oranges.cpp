int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int N=grid.size();
        int M=grid[0].size();
        int count=0,ans=0;
        queue<pair<int,int>>q;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                    
                else if(grid[i][j]==1)
                    count++;
            }
        }
        
        while(count!=0&&!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int new_x=x+dx[k];
                    int new_y=y+dy[k];
                    if((new_x>=0&&new_y>=0&&new_x<N&&new_y<M)&&grid[new_x][new_y]==1){
                        grid[new_x][new_y]=2;
                        count--;
                        q.push({new_x,new_y});
                    }
                }
            }
            ans++;
        }
        return count==0?ans:-1;
    }
};
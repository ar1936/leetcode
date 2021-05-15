    int N,M;
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
class Solution {
public:
  
    bool isValid(int x,int y){
        return (0<=x)&&(x<N)&&(0<=y)&&(y<M);
    }
    int numIslands(vector<vector<char>>& mat) {
        N= mat.size(); M=mat[0].size();
        int ans=0;
        vector<vector<bool>>visited(301,vector<bool>(301));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!visited[i][j]&&mat[i][j]=='1'){
                    ans++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    visited[i][j]=true;
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int new_x=x+dx[k];
                            int new_y=y+dy[k];
                            if(isValid(new_x,new_y)&&!visited[new_x][new_y]&&mat[new_x][new_y]=='1'){
                                q.push({new_x,new_y});
                                visited[new_x][new_y]=true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// int dx[]={1,0,0,-1};
// int dy[]={0,1,-1,0};
// class Solution {
// public:
//     bool isValid(int x,int y,int N,int M){
//         return (x>=0&&x<N&&y>=0&&y<M);
//     }
//     vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//         int N=matrix.size();
//         int M=matrix[0].size();
//         if(N==0)
//             return matrix;
//         vector<vector<int>>distance(N,vector<int>(M,INT_MAX));
//         queue<pair<int,int>>q;
//         for(int i=0;i<N;i++){
//             for(int j=0;j<M;j++){
//                 if(matrix[i][j]==0)
//                 {
//                     q.push({i,j});
//                     distance[i][j]=0;
//                 }
//                     while(!q.empty()){
//                         int x = q.front().first;
//                         int y = q.front().second;
//                         q.pop();
//                         for(int k=0;k<4;k++){
//                             int new_x=x+dx[k];
//                             int new_y=y+dy[k];
//                             if(isValid(new_x,new_y,N,M))
//                             {
//                                 if(distance[new_x][new_y]>distance[x][y]+1){
//                                 distance[new_x][new_y]=distance[x][y]+1;
//                                 q.push({new_x,new_y});
//                                 }
//                             }
//                         }
                    
//                 }
//             }
//         }
//         return distance;
//     }
// };

class Solution {
public:
vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int> > q;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] == 0) {
                dist[i][j] = 0;
                q.push({ i, j }); //Put all 0s in the queue.
            }

    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
            if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                    dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                    q.push({ new_r, new_c });
                }
            }
        }
    }
    return dist;
    }
};